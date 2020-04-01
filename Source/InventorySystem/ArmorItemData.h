#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ArmorItemData.generated.h"



USTRUCT(BlueprintType)
struct FArmorItemData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	FArmorItemData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MinPhysicalResistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MaxPhysicalResistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MinMagicResistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MaxMagicResistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MaxStackSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* Thumbnail;


	bool operator==(const FArmorItemData& OtherItem) const
	{
		if (ItemID == OtherItem.ItemID) return true;
		return false;
	}

};



