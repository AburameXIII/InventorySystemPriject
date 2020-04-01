// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemData.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class INVENTORYSYSTEM_API UItem : public UObject
{
	GENERATED_BODY()

	public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemID")
			FName ItemID;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemName")
			FString ItemName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemName")
			FString ItemDescription;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaxStackSize")
			int MaxStackSize;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			UTexture2D* Thumbnail;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			EItemType ItemType;

		FORCEINLINE bool operator==(const UItem& OtherItem) const
		{
			return ItemID.IsEqual(OtherItem.ItemID);
		}

		//virtual function to be overwritten in the subclasses
		UFUNCTION(BlueprintCallable, Category = "Utils")
			virtual FString GetOtherInformation();


		
};
