#include "AIActionRenderComponent.h"
#include "Net/UnrealNetwork.h"

UAIActionRenderComponent::UAIActionRenderComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Owner = NULL;
    this->GameConfigSubsystem = NULL;
    this->NPCConfig = NULL;
}

void UAIActionRenderComponent::StartRender(const FGameplayTag& InActionTag) {
}

void UAIActionRenderComponent::StartCooldown() {
}

void UAIActionRenderComponent::RenderVFX_Implementation() {
}

void UAIActionRenderComponent::Render_Implementation(const int32 SoundIdx, const FGameplayTag ActionTag) {
}

void UAIActionRenderComponent::OnRep_ActionRenderInfo() {
}

void UAIActionRenderComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UAIActionRenderComponent, ActionRenderInfo);
}


