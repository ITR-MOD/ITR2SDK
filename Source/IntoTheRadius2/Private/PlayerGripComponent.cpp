#include "PlayerGripComponent.h"

UPlayerGripComponent::UPlayerGripComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsHandClimbing = false;
    this->ClimbingHand = EVRHand::Left;
    this->bIsClimbingObjectRelative = false;
    this->bForceOverlapOnlyGripChecks = false;
    this->bAlwaysAllowClimbing = false;
    this->GripTraceLength = 0.00f;
    this->bLimitMaxThrowVelocity = false;
    this->MaximumThrowingVelocity = 0.00f;
    this->MassScalerMin = 0.00f;
    this->ThrowingMassMaximum = 0.00f;
    this->bScaleVelocityByMass = false;
    this->bSampleGripVelocity = false;
    this->bUseControllerVelocityOnRelease = false;
    this->bDisableMovement = false;
}

bool UPlayerGripComponent::UnlockGrip_Implementation(EVRHand Hand, ARadiusGrippableActorBase* GripActor, bool bUseFakeGrip) {
    return false;
}

void UPlayerGripComponent::StopDistanceGrip(EVRHand Hand) {
}

void UPlayerGripComponent::StartDistanceGrip(UPrimitiveComponent* Primitive, EVRHand Hand, FVector GripRelativeLocation, FQuat GripRelativeRotation) {
}

void UPlayerGripComponent::SetupHand(EVRHand Hand, UGripMotionControllerComponent* Controller, USphereComponent* GrabSphere) {
}

void UPlayerGripComponent::SetHoldingX(bool bHolding) {
}

void UPlayerGripComponent::SetHoldingA(bool bHolding) {
}

void UPlayerGripComponent::ServerRequestOwnership_Implementation(EVRHand Hand, UPrimitiveComponent* Target) {
}

bool UPlayerGripComponent::LockGrip_Implementation(EVRHand Hand, ARadiusGrippableActorBase* GripActor, URadiusHandSocketComponent*& HandSocket, bool bUseFakeGrip) {
    return false;
}

bool UPlayerGripComponent::IsGripLocked(EVRHand Hand, FGameplayTag GripQueryType, const URadiusHandSocketComponent* HandSocket) const {
    return false;
}

bool UPlayerGripComponent::IsAltInteraction(EVRHand Hand) const {
    return false;
}

ACharacter* UPlayerGripComponent::GetOwnerCharacter() const {
    return NULL;
}

TArray<URadiusHandSocketComponent*> UPlayerGripComponent::GetOverlappedHandSockets(TArray<AActor*> OverlappedActors, FGameplayTagContainer GripTags, UGripMotionControllerComponent* MotionController) {
    return TArray<URadiusHandSocketComponent*>();
}

USphereComponent* UPlayerGripComponent::GetGrabSphere(EVRHand Hand) {
    return NULL;
}

UGripMotionControllerComponent* UPlayerGripComponent::GetController(EVRHand Hand) {
    return NULL;
}

void UPlayerGripComponent::FindClosestGrippableHandSockets(TArray<URadiusHandSocketComponent*> InputSocketArray, TMap<FGameplayTag, URadiusHandSocketComponent*>& HandSockets, EVRHand Hand, UGripMotionControllerComponent* QueryController, FVector HandDirection, bool& bOutDistanceGrip, bool bIsDistanceGrip) {
}

void UPlayerGripComponent::FillGripOverlap(EVRHand Hand, URadiusHandSocketComponent* HandSocket, bool bIsDistanceGrip) {
}



void UPlayerGripComponent::ClientOwnershipRejected_Implementation(EVRHand Hand) {
}

void UPlayerGripComponent::ClearGripOverlap(EVRHand Hand) {
}



