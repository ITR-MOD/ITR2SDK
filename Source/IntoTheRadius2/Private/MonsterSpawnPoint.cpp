#include "MonsterSpawnPoint.h"

AMonsterSpawnPoint::AMonsterSpawnPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsIndependentFromDifficulty = false;
    this->AreaRadius = 0.00f;
    this->CurrentAIPath = NULL;
}

void AMonsterSpawnPoint::SpawnNext(const bool bSkipFirst) {
}


FTransform AMonsterSpawnPoint::GetSpawnTransform_Implementation() {
    return FTransform{};
}


