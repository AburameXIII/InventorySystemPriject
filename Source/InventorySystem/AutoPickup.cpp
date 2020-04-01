// Fill out your copyright notice in the Description page of Project Settings.


#include "AutoPickup.h"
#include "InventoryController.h"

//Constructor that sets up a mesh and an itemID 
AAutoPickup::AAutoPickup()
{
    PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
    RootComponent = Cast<USceneComponent>(PickupMesh);

    ItemID = FName("No ID");
}

//Collects the item and destroys it if it can add to the inventory
void AAutoPickup::Collect_Implementation(APlayerController* Controller)
{
    AInventoryController* IController = Cast<AInventoryController>(Controller);
    if(IController->AddItemToInventoryByID(ItemID))
        Destroy();
}

//Returns the ItemID
FName AAutoPickup::GetItemID()
{
    return ItemID;
}
