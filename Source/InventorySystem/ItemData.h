// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "ItemData.generated.h"

UENUM(BlueprintType, meta = (DisplayName = "EItemType"))
enum class EItemType : uint8
{
	Pet 		UMETA(DisplayName = "Pet"),
	Consumable 	UMETA(DisplayName = "Consumable"),
	Quest		UMETA(DisplayName = "Quest"),
	Equipment	UMETA(DisplayName = "Equipment")
};


USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	FItemData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID;


	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EItemType ItemType;
	

	bool operator==(const FItemData& OtherItem) const
	{
		if (ItemID == OtherItem.ItemID) return true;
		return false;
	}

};



