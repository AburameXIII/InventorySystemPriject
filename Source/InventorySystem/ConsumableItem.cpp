// Fill out your copyright notice in the Description page of Project Settings.


#include "ConsumableItem.h"

//Initializes the Consumable Item based on its Database data
void UConsumableItem::init(FConsumableItemData* data) {
	ItemID = data->ItemID;
	ItemName = data->ItemName;
	ItemDescription = data->ItemDescription;
	RestoreAmount = data->RestoreAmount;
	Value = data->Value;
	MaxStackSize = data->MaxStackSize;
	Thumbnail = data->Thumbnail;
	ItemType = EItemType::Consumable;
}

//Information available and unique to consumable items
FString UConsumableItem::GetOtherInformation() {
	FString otherInfo("Restores ");
	otherInfo.Append(FString::FromInt(RestoreAmount));
	otherInfo.Append(" HP to your character.\n");
	return otherInfo;
}
