// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmorItem.h"

//Initializes an Armor Item based on its data from the database
void UArmorItem::init(FArmorItemData* data) {

	ItemID = data->ItemID;
	ItemName = data->ItemName;
	ItemDescription = data->ItemDescription;
	Value = data->Value;
	MaxStackSize = data->MaxStackSize;
	Thumbnail = data->Thumbnail;
	ItemType = EItemType::Equipment;

	PhysicalResistance =  roundf(FMath::RandRange(data->MinPhysicalResistance, data->MaxPhysicalResistance));
	MagicResistance = roundf(FMath::RandRange(data->MinMagicResistance, data->MaxMagicResistance));


}


//Returns a string that gives information unique to armor items
FString UArmorItem::GetOtherInformation() {
	FString otherInfo("");
	otherInfo.Append(FString::FromInt(PhysicalResistance));
	otherInfo.Append(" Physical Resistance\n");
	otherInfo.Append(FString::FromInt(MagicResistance));
	otherInfo.Append(" Magic Resistance\n");
	return otherInfo;
}