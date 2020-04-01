// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interactable.h"
#include "InventoryItem.h"
#include <InventorySlot.h>
#include "ItemFactory.h"
#include "InventoryController.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API AInventoryController : public APlayerController
{   public:
    
        GENERATED_BODY()
    
        AInventoryController();

        //Used to reload inventory UI when a change in the inventory is done.
        UFUNCTION(BlueprintImplementableEvent)
        void ReloadInventory();

        UFUNCTION(BlueprintCallable, Category = "Utils")
        bool AddItemToInventoryByID(FName ID);

        UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
        class AInteractable* CurrentInteractable;

        UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
        TArray<UInventorySlot*> Inventory;

        UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
        int32 Money;

        UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 InventorySlotLimit;

        UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
        UItemFactory* ItemFactory;

        UFUNCTION(BlueprintCallable, Category = "Utils")
        void RemoveItem(int slot);

        UFUNCTION(BlueprintCallable, Category = "Utils")
        bool MoveItem(int slot1, int slot2);

        UFUNCTION(BlueprintCallable, Category = "Utils")
        bool Split(int slot1, int slot2, int quantity);

        UFUNCTION(BlueprintCallable, Category = "Utils")
        bool CanSplit(int slot);

        UFUNCTION(BlueprintCallable, Category = "Utils")
        bool ValidSplit(int slot);

        UFUNCTION(BlueprintCallable, Category = "Utils")
        void Init(int32 Slots);

        
        UFUNCTION(BlueprintCallable, Category = "Utils")
        void SortItemsDefault();

        UFUNCTION(BlueprintCallable, Category = "Utils")
            void SortItemsNames();

        UFUNCTION(BlueprintCallable, Category = "Utils")
            void SortItemsQuantity();

        UFUNCTION(BlueprintCallable, Category = "Utils")
            void SortItemsType();

        UFUNCTION(BlueprintCallable, Category = "Utils")
        TArray<UInventorySlot*> FilterItems(EItemType type);


    protected:
        void Interact();

        virtual void SetupInputComponent() override;

        
        
	
    
    
	
};
