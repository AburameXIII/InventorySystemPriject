// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <InventorySystem\Item.h>
#include "InventoryGameState.h"

#include "ItemFactory.generated.h"


/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UItemFactory : public UObject
{
	GENERATED_BODY()

	public:
		UItemFactory();

		UItem* CreateItem(FName ItemID);


		//Main Item Database that contains every item 
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			class UDataTable* ItemDB;

		//Database of the ConsumableItems
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			class UDataTable* ConsumableItemDB;

		//Database of the Armor/EquipmentItems
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			class UDataTable* ArmorItemDB;
	
};
