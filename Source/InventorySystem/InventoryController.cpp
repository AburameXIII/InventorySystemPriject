// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryController.h"
#include "InventoryGameState.h"
#include "ItemData.h"
#include "InventorySystemCharacter.h"


AInventoryController::AInventoryController()
{
    
    InventorySlotLimit = 10;

    //Initializes an Inventory of size 10
    for (int i = 0; i < InventorySlotLimit; i++) {
        FString SlotName = FString::Printf(TEXT("Slot %d"), i);
        UInventorySlot* s = CreateDefaultSubobject<UInventorySlot>(*SlotName);
        Inventory.Add(s);
        s->Slot = i;
    }

    //Initializes the Item Factory
    ItemFactory = CreateDefaultSubobject<UItemFactory>(TEXT("ItemFactoryyy"));

}

//Because we probably need to create a blueprint class that inherits from this class, the constructor won't work
//good since some references might be lost and the garbage collector will get the objects. To avoid this, we create
//an Init function to be called on the blueprint class at the beginning.
void AInventoryController::Init(int32 Slots) {
    InventorySlotLimit = Slots;

    Inventory.Empty();
    for (int i = 0; i < InventorySlotLimit; i++) {
        UInventorySlot* s = NewObject<UInventorySlot>();
        Inventory.Add(s);
        s->Slot = i;
    }

    ItemFactory = NewObject<UItemFactory>();
}

//Adds Item to Inventory. Returns true if it suceeded, false otherwise.
bool AInventoryController::AddItemToInventoryByID(FName ID)
{
    //Creates the Item Object
    UItem* ItemToAdd = ItemFactory->CreateItem(ID);

    //If Suceeded, will iterate through the slots and try to add the item
    if (ItemToAdd)
    {
        for (auto Slot(Inventory.CreateIterator()); Slot; Slot++)
        {
            if ((*Slot)->AddItem(ItemToAdd)) {
                ReloadInventory();
                return true;
            }
            else continue;
        }
    }
    return false;
}

//Removes Item from a specific slot
void AInventoryController::RemoveItem(int slot) {
    Inventory[slot]->RemoveItem();
}

//Moves item from slot1 to slot2. Returns true if suceed, false otherwise.
bool AInventoryController::MoveItem(int slot1, int slot2) {

    //If the origin slot is somehow empty or trying to move to the same slot, just ignore and do nothing
    if (Inventory[slot1]->IsEmpty()) return false;
    if (slot1 == slot2) return false;

    //If the end slot is empty, simply move from one slot to the other
    if (Inventory[slot2]->IsEmpty()) {
        return Inventory[slot1]->MoveTo(Inventory[slot2]);
    }
    else {
        //If the end slot has the same type of item and...
        if (Inventory[slot1]->SameItem(Inventory[slot2])) {
            //... can be stacked, tries to stack
            if (Inventory[slot2]->Stackable()) {
                return Inventory[slot1]->MoveStacks(Inventory[slot2]);
            }
            //... can't be stacked, simply swaps items around
            else {
                return Inventory[slot1]->Swap(Inventory[slot2]);
            }

        }
        //Item is not the same type so simply swap items around
        else {
            return Inventory[slot1]->Swap(Inventory[slot2]);
        }
    }

}

//Returns true if the item in the current slot can be split
bool AInventoryController::CanSplit(int slot) {
    return Inventory[slot]->Stackable();
}

//Returns true if the end slot of the split is empty
bool AInventoryController::ValidSplit(int slot) {
    return Inventory[slot]->IsEmpty();
}

//Splits the item on slot1 to slot2 with a certain quantity. Returns true if suceeds, false otherwise.
bool AInventoryController::Split(int slot1, int slot2, int quantity) {
    return Inventory[slot1]->SplitStacks(Inventory[slot2], quantity);
}

//Filters items according to type. Returns an Array of slots of items of that type
TArray<UInventorySlot*> AInventoryController::FilterItems(EItemType type) {
    TArray<UInventorySlot*> FilteredItems;


    for (auto Slot(Inventory.CreateIterator()); Slot; Slot++)
    {

        if ((*Slot)->Quantity > 0 && ((*Slot)->Item)->ItemType == type) {
            FilteredItems.Add(*Slot);
        }
    }

    return FilteredItems;
}

//For Interaction with interactable items
void AInventoryController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("Interact", IE_Pressed, this, &AInventoryController::Interact);
}

//Interact with the current interactable
void AInventoryController::Interact()
{
    if (CurrentInteractable)
    {
        CurrentInteractable->Interact(this);
    }
}

//Sort item slots based on their index.
void AInventoryController::SortItemsDefault() {
    Inventory.StableSort([](const UInventorySlot& A,const UInventorySlot& B) {
        return A.Slot < B.Slot;
        });
}
//Sort item slots based on item name
void AInventoryController::SortItemsNames() {
    Inventory.StableSort([](const UInventorySlot& A,const UInventorySlot& B) {
        if (B.Quantity == 0) return true;
        if (A.Quantity == 0) return false;

        return A.Item->ItemName < B.Item->ItemName;
        });
}

//Sort item slots based on item quantities on the slots
void AInventoryController::SortItemsQuantity() {
    Inventory.StableSort([](const UInventorySlot& A, const UInventorySlot& B) {
        return A.Quantity > B.Quantity;
        });
}

//Sort item slots based on item types
void AInventoryController::SortItemsType() {
    Inventory.StableSort([](const UInventorySlot& A, const UInventorySlot& B) {
        if (B.Quantity == 0) return true;
        if (A.Quantity == 0) return false;

        return A.Item->ItemType > B.Item->ItemType;
        });
}