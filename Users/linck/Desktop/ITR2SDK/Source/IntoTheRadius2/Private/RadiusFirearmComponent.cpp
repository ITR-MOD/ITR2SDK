#include "RadiusFirearmComponent.h"
#include "Net/UnrealNetwork.h"

URadiusFirearmComponent::URadiusFirearmComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ChamberAmmoSound = NULL;
    this->bCanLoadToChamber = false;
    this->bDrawEjectionDebug = false;
    this->bLeaveUnshotAmmoInside = false;
    this->bCanShootCacheForABP = false;
    this->RelevantMuzzle = NULL;
    this->RelevantMagazine = NULL;
    this->bHasShootInput = false;
}

void URadiusFirearmComponent::TryShoot_Implementation() {
}

bool URadiusFirearmComponent::TryReload_Implementation(const bool bIsManual) {
    return false;
}

bool URadiusFirearmComponent::TryNextAutomaticFire_Implementation() {
    return false;
}

void URadiusFirearmComponent::ToggleChamberLoading(bool bOn) {
}

FGameplayTag URadiusFirearmComponent::SwitchNextFireMode() {
    return FGameplayTag{};
}

void URadiusFirearmComponent::StartFire_Implementation() {
}

void URadiusFirearmComponent::ShootNext() {
}

bool URadiusFirearmComponent::SetSliderLock(const bool bSet, const bool bForce) {
    return false;
}

void URadiusFirearmComponent::SetCurrentFireMode(const FGameplayTag NewFireMode) {
}

bool URadiusFirearmComponent::SetAmmoInChamberTag(UActorComponent* BulletComponent, const FGameplayTag AmmoTag, bool bSetShell) {
    return false;
}

void URadiusFirearmComponent::Server_ShootProjectile_Implementation(const FGameplayTag BulletTag) {
}

void URadiusFirearmComponent::Server_SetShootingInputUnreliable_Implementation(const bool NewInput) {
}

void URadiusFirearmComponent::Server_RollDysfunction_Implementation(FGameplayTag PreRolledTag) {
}

void URadiusFirearmComponent::Server_ClearDysfunction_Implementation(FGameplayTag DysfunctionToClear) {
}

void URadiusFirearmComponent::ReplaceBulletWithShell_Implementation(UActorComponent* BulletComponent) {
}

void URadiusFirearmComponent::OnRep_bHasShootInput() const {
}

void URadiusFirearmComponent::OnItemAdditionalTagChanged(const FGameplayTag Tag, const bool bAdded) {
}

void URadiusFirearmComponent::OnDynamicDataUnlinked(URadiusItemDynamicData* PreviousDynamicData) {
}

void URadiusFirearmComponent::OnDynamicDataLinked() {
}

void URadiusFirearmComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& HitResult) {
}

void URadiusFirearmComponent::Multicast_UpdateBulletOnClients_Implementation(FGameplayTag OtherActorTypeID, int32 BulletComponentID) {
}

void URadiusFirearmComponent::Multicast_ShootProjectile_Implementation(const FGameplayTag BulletTag) {
}

bool URadiusFirearmComponent::IsSliderLock() {
    return false;
}

bool URadiusFirearmComponent::IsOnSafety() {
    return false;
}

bool URadiusFirearmComponent::IsAcceptsAmmoType(const FGameplayTag AmmoType) {
    return false;
}

void URadiusFirearmComponent::InitializeMagazine() {
}

bool URadiusFirearmComponent::HasDysfunction() {
    return false;
}

bool URadiusFirearmComponent::HasAmmoInBarrel_Implementation(bool& bIsShell) {
    return false;
}

UActorComponent* URadiusFirearmComponent::GetUnejectedBulletComponent(bool bOnlyNotShell) {
    return NULL;
}

FGameplayTag URadiusFirearmComponent::GetCurrentFireModeTag() {
    return FGameplayTag{};
}

FGameplayTag URadiusFirearmComponent::GetCurrentDysfunction() {
    return FGameplayTag{};
}

void URadiusFirearmComponent::EndFire_Implementation() {
}

FGameplayTag URadiusFirearmComponent::EjectChamber_Implementation(bool bIsManual) {
    return FGameplayTag{};
}

bool URadiusFirearmComponent::DeliverAmmoFromMagToChamber_Implementation() {
    return false;
}

void URadiusFirearmComponent::ClearDysfunction(FGameplayTag DysfunctionToClear) {
}

bool URadiusFirearmComponent::CanShoot_Implementation() {
    return false;
}

void URadiusFirearmComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(URadiusFirearmComponent, bHasShootInput);
}


