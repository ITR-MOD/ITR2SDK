#include "CombatZone.h"

ACombatZone::ACombatZone(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ZoneRadius = 500.00f;
}

bool ACombatZone::IsActorInside(const AActor* Actor) const {
    return false;
}


