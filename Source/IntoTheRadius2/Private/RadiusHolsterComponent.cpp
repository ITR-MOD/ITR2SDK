#include "RadiusHolsterComponent.h"
#include "Net/UnrealNetwork.h"

URadiusHolsterComponent::URadiusHolsterComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bOnlyOwnerCanInteract = false;
    this->bDisableWhenOnPlayer = false;
    this->bDisableWhenNotInHands = false;
    this->bAllowInteractionWhenDisabled = true;
    this->bCanBeArmored = false;
    this->bCanDistanceGripStoredItems = false;
    this->bPreventCollisionWithAttachedItem = true;
    this->bOnlyGripInOverlapZone = false;
    this->bOnlyDetachTopAttachment = false;
    this->bVisualHandLock = false;
    this->bOnlyGripItemByMainHandSocket = false;
    this->bIsDisabled = false;
    this->OptionalCollision = NULL;
    this->HolsteredActor = NULL;
    this->HolsterCacheForReps = NULL;
}

void URadiusHolsterComponent::WaitForSyncTransformComponent() {
}

void URadiusHolsterComponent::UpdateItemAsInContainer(AActor* ItemActor) {
}

void URadiusHolsterComponent::SpawnSavedItems() {
}

void URadiusHolsterComponent::SetHolsteredActor_Implementation(ARadiusGrippableActorBase* ActorToHolster) {
}

void URadiusHolsterComponent::SetHolsterDisabled(bool bNewDisabled) {
}

void URadiusHolsterComponent::RemoveHolsteredActor() {
}


void URadiusHolsterComponent::OnRep_HolsteredActor_Implementation() {
}

void URadiusHolsterComponent::OnEndOverlapCustomCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void URadiusHolsterComponent::OnDataUnlinking(URadiusItemDynamicData* PreviousDynamicData) {
}

void URadiusHolsterComponent::OnBeginOverlapCustomCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool URadiusHolsterComponent::IsReadyToHolster() const {
    return false;
}

bool URadiusHolsterComponent::IsDisabled() const {
    return false;
}

void URadiusHolsterComponent::InitializeContainer_Internal() {
}

void URadiusHolsterComponent::HandleHolsterEndOverlap_Implementation(AActor* OtherActor, UPrimitiveComponent* OverlapComponent) {
}

void URadiusHolsterComponent::HandleHolsteredActorGrip_Implementation(UGripMotionControllerComponent* MotionController, const FBPActorGripInformation& GripInfo) {
}

void URadiusHolsterComponent::HandleHolsterBeginOverlap_Implementation(AActor* OtherActor, UPrimitiveComponent* OverlapComponent) {
}

FString URadiusHolsterComponent::GetOwnerContainerUid() const {
    return TEXT("");
}

ARadiusGrippableActorBase* URadiusHolsterComponent::GetHolsteredActor() const {
    return NULL;
}


void URadiusHolsterComponent::DoInstantHolster() {
}

void URadiusHolsterComponent::Continue_SpawnSavedItems(AActor* ItemActor, URadiusItemDynamicData* ItemDynamicData) {
}

void URadiusHolsterComponent::Continue_InstantHolsterActor(URadiusHolsterComponent* HolsterComponent) {
}

void URadiusHolsterComponent::Continue_InitializeContainer_Internal() {
}

void URadiusHolsterComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(URadiusHolsterComponent, HolsteredActor);
}


