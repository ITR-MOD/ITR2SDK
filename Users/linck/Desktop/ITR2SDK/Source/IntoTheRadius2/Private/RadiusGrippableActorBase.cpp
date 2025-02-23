#include "RadiusGrippableActorBase.h"
#include "SyncTransformComponent.h"

ARadiusGrippableActorBase::ARadiusGrippableActorBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SyncTransfromComponent = CreateDefaultSubobject<USyncTransformComponent>(TEXT("SyncTransformComponent"));
}

void ARadiusGrippableActorBase::StartFloating_Implementation() {
}

void ARadiusGrippableActorBase::ServerRepMovement_Implementation(const FRepMovement& InMovement) {
}

void ARadiusGrippableActorBase::ServerReleaseOwnership_Implementation() {
}

bool ARadiusGrippableActorBase::PollSmoothRemove() {
    return false;
}

bool ARadiusGrippableActorBase::PollSendRepMovement() {
    return false;
}

UStaticMeshComponent* ARadiusGrippableActorBase::GetStaticMeshComponent_Implementation() const {
    return NULL;
}

USkeletalMeshComponent* ARadiusGrippableActorBase::GetSkeletalMeshComponent_Implementation() const {
    return NULL;
}


