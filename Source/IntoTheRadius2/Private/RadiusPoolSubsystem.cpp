#include "RadiusPoolSubsystem.h"
#include "Templates/SubclassOf.h"

URadiusPoolSubsystem::URadiusPoolSubsystem() {
}

void URadiusPoolSubsystem::Server_ReturnActor_Implementation(AActor* Actor) {
}

bool URadiusPoolSubsystem::ReturnActor(AActor* Actor) {
    return false;
}

void URadiusPoolSubsystem::PrintPools() {
}

bool URadiusPoolSubsystem::IsActorInPool(AActor* Actor) {
    return false;
}

void URadiusPoolSubsystem::GetSeamlessTravelActorList(TArray<AActor*>& ActorList, const bool bReplicated, const bool bReturnToPool) {
}

AActor* URadiusPoolSubsystem::GetActor(const TSubclassOf<AActor> ActorClass, const FTransform Transform, AActor* Owner, APawn* Instigator, FItemConfiguration ItemConfiguration) {
    return NULL;
}

void URadiusPoolSubsystem::FillingPoolsStep() {
}


