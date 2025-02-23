#include "RadiusGameInstance.h"

URadiusGameInstance::URadiusGameInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    
    this->IngameMenuClass = NULL;
    this->bIsSaveLoadTemporarilyDisabled = false;
    this->LevelLoadedEventTrigger = NULL;
    this->BPRadiusCheatSubsystem = NULL;
    this->BPRadiusAnalyticsSubsystem = NULL;
}

void URadiusGameInstance::OnLevelLoaded() {


}




