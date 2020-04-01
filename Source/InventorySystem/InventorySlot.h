// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <InventorySystem\Item.h>
#include "InventorySlot.generated.h"


/**
 * 
 */
UCLASS(BlueprintType)
class INVENTORYSYSTEM_API UInventorySlot : public UObject
{
	GENERATED_BODY()

	public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slot")
		int Slot;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Qauntity")
		int Quantity;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		UItem* Item;

		UInventorySlot();

		UInventorySlot(const FObjectInitializer& ObjectInitializer);

		bool IsEmpty();

		bool AddItem(UItem* item);

		void RemoveItem();

		bool MoveTo(UInventorySlot* otherSlot);

		bool SameItem(UInventorySlot* otherSlot);

		bool Swap(UInventorySlot* otherSlot);

		bool Stackable();

		bool IsMaxStacks();

		bool MoveStacks(UInventorySlot* otherSlot);

		bool SplitStacks(UInventorySlot* otherSlot, int quantity);
	
};
