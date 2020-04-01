// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlot.h"


UInventorySlot::UInventorySlot()
{
	Slot = 0;
	Quantity = 0;
}

UInventorySlot::UInventorySlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Slot = 0;
	Quantity = 0;
}



//Inventory Slot is empty if its quantity is 0
bool UInventorySlot::IsEmpty() {
	return !Quantity;
}


bool UInventorySlot::AddItem(UItem* item) {
	//If Quantity is 0, then it means the slot is empty so the item gets added and exits sucessfully
	if (Quantity == 0) {
		Item = item;
		Quantity = 1;
		return true;
	}
	//If the item we are trying to add is not the same as the one currently taking this slot, then dont add and exit
	if (!((*Item) == (*item))) return false;
	//If the item we are trying to add already exceeded the maxstacks, then dont add and exit
	if (Item->MaxStackSize == Quantity) return false;
	//If its the same type of item and it didnt exceed maxstacks, increase its current quantity by 1
	Quantity++;
	return true;
}



void UInventorySlot::RemoveItem() {
	Item = nullptr; //maybe free memory here?
	Quantity = 0;
}

bool UInventorySlot::MoveTo(UInventorySlot* newSlot){
	//If the slot is the same, ignore
	if (Slot == newSlot->Slot) return false;

	newSlot->Item = Item;
	newSlot->Quantity = Quantity;

	this->Item = nullptr;
	this->Quantity = 0;
	return true;
}

bool UInventorySlot::SameItem(UInventorySlot* newSlot){
	return (*Item) == (*(newSlot->Item));
}


bool UInventorySlot::Swap(UInventorySlot* otherSlot) {
	if (Slot == otherSlot->Slot) return false;

	UItem* ItemAux = otherSlot->Item;
	int QuantityAux = otherSlot->Quantity;

	otherSlot->Item = Item;
	otherSlot->Quantity = Quantity;

	this->Item = ItemAux;
	this->Quantity = QuantityAux;

	return true;
}

bool UInventorySlot::Stackable() {
	if (Item == nullptr) return false;

	return Item->MaxStackSize != 1;
}

bool UInventorySlot::IsMaxStacks() {
	if (Item == nullptr) return false;

	return Item->MaxStackSize == Quantity;
}

bool UInventorySlot::MoveStacks(UInventorySlot* otherSlot) {
	if (Slot == otherSlot->Slot) return false;
	
	//Number of items the slot can receive until the stacks are maxed.
	int AvailableSpace = Item->MaxStackSize - otherSlot->Quantity;

	//If what we have is less than the available space in the end slot, then this slot ceases to have anything
	if (AvailableSpace >= Quantity) {
		Item = nullptr;
		otherSlot->Quantity += Quantity;
		Quantity = 0;
	}
	//increases the quantity of end slot to its max and decreases the quantity of the origin slot by the quantity moved
	else {
		otherSlot->Quantity += AvailableSpace;
		Quantity -= AvailableSpace;
	}
	
	return true;
}


bool UInventorySlot::SplitStacks(UInventorySlot* otherSlot, int quantity) {
	if (quantity > Quantity) return false;
	

	otherSlot->Item = Item;
	otherSlot->Quantity = quantity;
	this->Quantity -= quantity;

	//If splitting, the max quantity was chosen and this current slot now has quantity 0, get rid of the item
	if (Quantity == 0) {
		Item = nullptr; //free memory or garbage collected?
	}

	return true;
}