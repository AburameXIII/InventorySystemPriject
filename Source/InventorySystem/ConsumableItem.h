// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "ConsumableItemData.h"
#include "ConsumableItem.generated.h"


/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UConsumableItem : public UItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
		int32 Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RestoreAmount")
		int32 RestoreAmount;
	
	void init(FConsumableItemData* data);

    FString GetOtherInformation();
};
