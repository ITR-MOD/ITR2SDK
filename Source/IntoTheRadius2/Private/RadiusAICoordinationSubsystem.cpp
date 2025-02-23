#include "RadiusAICoordinationSubsystem.h"

URadiusAICoordinationSubsystem::URadiusAICoordinationSubsystem() {
    this->NPCConfig = NULL;
    this->VantageCoverManager = NULL;
}

void URadiusAICoordinationSubsystem::UnRegisterNpc(ARadiusAIControllerBase* AIController) {
}

void URadiusAICoordinationSubsystem::UnOccupyAmbush(AController* InController) {
}

void URadiusAICoordinationSubsystem::SetAgentsStateIdleBeforeSave() {
}

bool URadiusAICoordinationSubsystem::RequestAttackRole(ARadiusAIControllerBase* AIController, FAttackRoleDelegate AttackRoleDelegate) {
    return false;
}

void URadiusAICoordinationSubsystem::RegisterNpc(ARadiusAIControllerBase* AIController) {
}

void URadiusAICoordinationSubsystem::OptimizeAndSelectAudibleAgents() {
}

void URadiusAICoordinationSubsystem::OccupyAmbush(AController* InController, const int32 AmbushIdx) {
}

void URadiusAICoordinationSubsystem::InitVantageCoverManager(AVantageCoverManager* InVantageCoverManager) {
}

bool URadiusAICoordinationSubsystem::HasAttackRole(ARadiusAIControllerBase* AIController) {
    return false;
}

TArray<AActor*> URadiusAICoordinationSubsystem::GetRelevantVantageCoverVolumes(const AActor* QuerierPawn, const float MaxAttackDist, const bool bIsVantageVolume) {
    return TArray<AActor*>();
}

FCreepAmbushInfo URadiusAICoordinationSubsystem::GetAmbush(AActor* QuerierPawn) {
    return FCreepAmbushInfo{};
}

TArray<APawn*> URadiusAICoordinationSubsystem::GetAgentsInRadius(const float Radius, const AActor* QuerierPawn) {
    return TArray<APawn*>();
}

TArray<APawn*> URadiusAICoordinationSubsystem::GetAgentsInGroup(const uint8 GroupID) const {
    return TArray<APawn*>();
}

void URadiusAICoordinationSubsystem::FreeAttackRole(ARadiusAIControllerBase* AIController) {
}


