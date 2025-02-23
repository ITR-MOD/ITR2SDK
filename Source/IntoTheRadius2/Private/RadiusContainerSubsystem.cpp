#include "RadiusContainerSubsystem.h"

URadiusContainerSubsystem::URadiusContainerSubsystem() {
}

void URadiusContainerSubsystem::UnregisterHolster(const FString& ContainerUid) {
}

bool URadiusContainerSubsystem::TryAttachItemToMostRelevantHolster(const EVRHand Hand, bool bAttachedItem) {
    return false;
}

void URadiusContainerSubsystem::RemoveItemFromTrack(const EVRHand Hand) {
}

void URadiusContainerSubsystem::RemoveAttachedItemFromTrack(const EVRHand Hand) {
}

void URadiusContainerSubsystem::RegisterHolster(const FString& ContainerUid, UObject* ContainerObject) {
}

void URadiusContainerSubsystem::PrintContainersStructure() {
}

bool URadiusContainerSubsystem::IsPlayerContainerID(const FString& ContainerID) const {
    return false;
}

FTransform URadiusContainerSubsystem::GetWorldTransform(const FString& ContainerUid, const FTransform& InitialTransform) {
    return FTransform{};
}

FString URadiusContainerSubsystem::GetTopParentContainerID(const FString& ContainerID) const {
    return TEXT("");
}

FItemContainerData URadiusContainerSubsystem::GetOrCreateItemContainer(const FString& ContainerID, UObject* ContainerObject, const FString& ParentID, FTransform RelativeTransform, bool bUpdateContainerObject) {
    return FItemContainerData{};
}

UObject* URadiusContainerSubsystem::GetMostRelevantContainer(const EVRHand Hand) {
    return NULL;
}

void URadiusContainerSubsystem::GetItemContainerBP(const FString& ContainerID, bool& bFound, FItemContainerData& ContainerData) {
}

TMap<FString, FItemContainerData> URadiusContainerSubsystem::GetContainers() {
    return TMap<FString, FItemContainerData>();
}

UObject* URadiusContainerSubsystem::GetContainerObject(const FString& ContainerID) {
    return NULL;
}

bool URadiusContainerSubsystem::GetAllPlayerItems(AActor* Player, TArray<ARadiusItemBase*>& Items) const {
    return false;
}

TArray<FString> URadiusContainerSubsystem::GetAllChildContainerIDs(const FString& ParentContainerID, bool bIncludeChildren) const {
    return TArray<FString>();
}

bool URadiusContainerSubsystem::CanAttachItemToMostRelevantHolster(const EVRHand Hand, bool bAttachedItem) const {
    return false;
}

void URadiusContainerSubsystem::AddItemToTrack(const EVRHand Hand, AActor* Item) {
}

void URadiusContainerSubsystem::AddContainerToContainer(const FString& ContainerID, const FString& ParentID, FTransform RelativeTransform) {
}

void URadiusContainerSubsystem::AddAttachedItemToTrack(const EVRHand Hand, AActor* AttachedItem) {
}


