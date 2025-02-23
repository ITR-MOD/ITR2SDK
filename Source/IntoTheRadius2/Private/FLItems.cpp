#include "FLItems.h"

UFLItems::UFLItems() {
}

void UFLItems::UpdateIgnoreCollisionForItemActorAttachments(AActor* ItemActor) {
}

void UFLItems::PackItemsToBox(UPrimitiveComponent* CollisionComp, TArray<AActor*> ActorsToPack, bool bExcludeNonFit, bool bProjectOnGround, TArray<AActor*>& Excluded) {
}

bool UFLItems::IsItemTrashMarked(UObject* WorldContext, AActor* Item) {
    return false;
}

bool UFLItems::IsItemAttachedToItem(UObject* WorldContext, UObject* Container) {
    return false;
}

bool UFLItems::IsInPlayerInventory(UObject* WorldContext, const FString& ContainerID) {
    return false;
}

AActor* UFLItems::GetTopParentItemActor(AActor* Actor) {
    return NULL;
}

UGripMotionControllerComponent* UFLItems::GetPrimaryControllerForActor(AActor* Actor) {
    return NULL;
}

AActor* UFLItems::GetParentItemActor(AActor* Actor) {
    return NULL;
}

float UFLItems::GetMaxDurabilityFromWeaponData(const UObject* WorldContextObject, const FWeaponStaticData& WeaponStaticData) {
    return 0.0f;
}

float UFLItems::GetMaxDurability(const UObject* WorldContextObject, const FRadiusItemStaticData& ItemStaticData) {
    return 0.0f;
}

float UFLItems::GetItemMaxDurability(const AActor* Item) {
    return 0.0f;
}

float UFLItems::GetItemDurabilityRatio(const AActor* Item) {
    return 0.0f;
}

TArray<FString> UFLItems::GetAllPlayerContainerIDs(UObject* WorldContext) {
    return TArray<FString>();
}

UObject* UFLItems::FindParentContainerByOverlap(UPrimitiveComponent* PrimitiveToCheck) {
    return NULL;
}

URadiusItemDynamicData* UFLItems::FindAttachedMagazine(const URadiusItemDynamicData* WeaponDynamicData) {
    return NULL;
}

URadiusItemDynamicData* UFLItems::FindAttachedArmorPlate(const UObject* WorldContextObject, const FString& ArmorInstanceID) {
    return NULL;
}

void UFLItems::DisableItemPrimitivesCollision(AActor* ItemActor) {
}

URadiusItemDynamicData* UFLItems::CreateNewDynamicDataFromActor(AActor* ItemActor) {
    return NULL;
}

URadiusItemDynamicData* UFLItems::CreateNewDynamicData(const UObject* WorldContext, FGameplayTag ItemType, FItemConfiguration ItemConfiguration, const FString& ParentContainer, FTransform Transform) {
    return NULL;
}

void UFLItems::CalculateSmoothingAlpha(bool& bOutIsAligned, float& OutAlignAlpha, USceneComponent* VRCameraRef, UMeshComponent* Mesh, const FName SocketName, const float DistanceLimit, const float AlphaThreshold) {
}

float UFLItems::CalculateContainerItemsWeight(UObject* WorldContext, const FString& ContainerID) {
    return 0.0f;
}

void UFLItems::CalculateChildItemsWeightAndCapacity(AActor* ItemActor, float& TotalWeight, float& Capacity) {
}

TArray<USceneComponent*> UFLItems::AddStartingGearToDynamicData(APawn* PlayerPawn, const bool bIsLeftHanded) {
    return TArray<USceneComponent*>();
}


