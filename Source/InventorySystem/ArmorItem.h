// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "ArmorItemData.h"
#include "ArmorItem.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UArmorItem : public UItem
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PhysicalResistance")
	int32 PhysicalResistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MagicResistance")
	int32 MagicResistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
	int32 Value;

	void init(FArmorItemData* data);

	FString GetOtherInformation();
	
};
