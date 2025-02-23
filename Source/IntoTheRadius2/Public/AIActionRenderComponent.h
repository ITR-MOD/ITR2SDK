#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "ActionRenderReplicationInfo.h"
#include "RadiusNPCStaticData.h"
#include "AIActionRenderComponent.generated.h"

class ACharacter;
class UNPCConfig;
class URadiusConfigurationSubsystem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS2_API UAIActionRenderComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ActionRenderInfo, meta=(AllowPrivateAccess=true))
    FActionRenderReplicationInfo ActionRenderInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRadiusNPCStaticData NPCStaticData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter* Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URadiusConfigurationSubsystem* GameConfigSubsystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UNPCConfig* NPCConfig;
    
public:
    UAIActionRenderComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void StartRender(const FGameplayTag& InActionTag);
    
protected:
    UFUNCTION(BlueprintCallable)
    void StartCooldown();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RenderVFX();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Render(const int32 SoundIdx, const FGameplayTag ActionTag);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_ActionRenderInfo();
    
};

