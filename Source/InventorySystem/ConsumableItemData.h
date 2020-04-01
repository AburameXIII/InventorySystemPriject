#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ConsumableItemData.generated.h"



USTRUCT(BlueprintType)
struct FConsumableItemData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	FConsumableItemData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 RestoreAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MaxStackSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* Thumbnail;


	bool operator==(const FConsumableItemData& OtherItem) const
	{
		if (ItemID == OtherItem.ItemID) return true;
		return false;
	}

};



