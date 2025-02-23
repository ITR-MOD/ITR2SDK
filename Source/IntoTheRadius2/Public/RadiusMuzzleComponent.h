#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "OnBulletFiredDelegate.h"
#include "RadiusComponentInterface.h"
#include "RadiusMuzzleComponentInterface.h"
#include "RadiusWeaponComponentInterface.h"
#include "WeaponStaticData.h"
#include "RadiusMuzzleComponent.generated.h"

class AActor;
class UActorComponent;
class USoundCue;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS2_API URadiusMuzzleComponent : public USceneComponent, public IRadiusComponentInterface, public IRadiusWeaponComponentInterface, public IRadiusMuzzleComponentInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ComponentPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* SoundDryShot;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnBulletFired OnBulletFired;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* ItemOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorComponent* ParticleComponent;
    
public:
    URadiusMuzzleComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool ShootBullet(FGameplayTag BulletTag, bool IsLastRound);
    
private:
    UFUNCTION(BlueprintCallable)
    void PlayParticleFX();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetOwnerWeaponStaticData(FWeaponStaticData& WeaponStaticData);
    

    // Fix for true pure virtual functions not being implemented
};

