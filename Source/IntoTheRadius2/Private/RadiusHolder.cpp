#include "RadiusHolder.h"
#include "Components/SceneComponent.h"

ARadiusHolder::ARadiusHolder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->bOnlyOwnerCanInteract = false;
    this->bPreventCollisionWithAttachedItem = true;
}

void ARadiusHolder::SpawnSavedItems() {
}

void ARadiusHolder::OnDataUnlinking_Implementation(URadiusItemDynamicData* PreviousDynamicData) {
}

void ARadiusHolder::InitializeContainer_Internal() {
}

void ARadiusHolder::Continue_SpawnSavedItems(AActor* ItemActor) {
}


