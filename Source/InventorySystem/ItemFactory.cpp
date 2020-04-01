// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemFactory.h"
#include "InventoryGameState.h"
#include "InventorySystemCharacter.h"
#include "ItemData.h"
#include "ConsumableItemData.h"
#include "ConsumableItem.h"
#include "ArmorItemData.h"
#include "ArmorItem.h"
#include <InventorySystem\ArmorItemData.h>

//gets the Items databases in the folder data with those given names
UItemFactory::UItemFactory() {
	static ConstructorHelpers::FObjectFinder<UDataTable> BP_ItemDB(TEXT("DataTable'/Game/Data/ItemDB.ItemDB'"));
	ItemDB = BP_ItemDB.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> BP_ConsumableItemDB(TEXT("DataTable'/Game/Data/ConsumableItemDB.ConsumableItemDB'"));
	ConsumableItemDB = BP_ConsumableItemDB.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> BP_ArmorItemDB(TEXT("DataTable'/Game/Data/ArmorItemDB.ArmorItemDB'"));
	ArmorItemDB = BP_ArmorItemDB.Object;
}


UItem* UItemFactory::CreateItem(FName ItemID) {

		//Gets the Item we want to add from the overall item database
		FItemData* ItemToAdd = ItemDB->FindRow<FItemData>(ItemID, "ItemID");
		//if it exists, sees what type of item it is and gets more information to create the item based on its type database
		if (ItemToAdd) {
			switch (ItemToAdd->ItemType) {

			case EItemType::Consumable:
			{
				FConsumableItemData* ConsumableItemToAdd = ConsumableItemDB->FindRow<FConsumableItemData>(ItemID, "ItemID");
				if (ConsumableItemToAdd) {
					UConsumableItem* NewConsumableItem = NewObject<UConsumableItem>();
					NewConsumableItem->init(ConsumableItemToAdd);
					return NewConsumableItem;
				}
			}
				break;
			case EItemType::Equipment:
			{
				FArmorItemData* ArmorItemToAdd = ArmorItemDB->FindRow<FArmorItemData>(ItemID, "ItemID");
				if (ArmorItemToAdd) {
					UArmorItem* NewArmorItem = NewObject<UArmorItem>();
					NewArmorItem->init(ArmorItemToAdd);
					return NewArmorItem;

				}
			}
				break;
			}
			
		}
		//if the item was not in the database, it will return a nullptr
		return nullptr;
}
	
	