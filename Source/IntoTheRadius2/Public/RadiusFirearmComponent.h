#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "MinMaxVector.h"
#include "NoParamsDelegateDelegate.h"
#include "OnFireModeChangedDelegate.h"
#include "OnShootInputChangedDelegate.h"
#include "OnSliderLockChangedDelegate.h"
#include "RadiusComponentInterface.h"
#include "RadiusFirearmComponentInterface.h"
#include "RadiusWeaponComponentInterface.h"
#include "RadiusFirearmComponent.generated.h"

class AActor;
class UActorComponent;
class UPrimitiveComponent;
class URadiusItemDynamicData;
class USoundBase;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS2_API URadiusFirearmComponent : public UBoxComponent, public IRadiusComponentInterface, public IRadiusWeaponComponentInterface, public IRadiusFirearmComponentInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* ChamberAmmoSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanLoadToChamber;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMinMaxVector EjectForceMultipliers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDrawEjectionDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLeaveUnshotAmmoInside;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanShootCacheForABP;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFireModeChanged OnFireModeChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnShootInputChanged OnShootInputChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSliderLockChanged OnSliderLock;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNoParamsDelegate OnAmmoInserted;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorComponent* RelevantMuzzle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorComponent* RelevantMagazine;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_bHasShootInput, meta=(AllowPrivateAccess=true))
    bool bHasShootInput;
    
public:
    URadiusFirearmComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TryShoot();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool TryReload(const bool bIsManual);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool TryNextAutomaticFire();
    
public:
    UFUNCTION(BlueprintCallable)
    void ToggleChamberLoading(bool bOn);
    
protected:
    UFUNCTION(BlueprintCallable)
    FGameplayTag SwitchNextFireMode();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartFire();
    
private:
    UFUNCTION(BlueprintCallable)
    void ShootNext();
    
protected:
    UFUNCTION(BlueprintCallable)
    bool SetSliderLock(const bool bSet, const bool bForce);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentFireMode(const FGameplayTag NewFireMode);
    
    UFUNCTION(BlueprintCallable)
    bool SetAmmoInChamberTag(UActorComponent* BulletComponent, const FGameplayTag AmmoTag, bool bSetShell);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ShootProjectile(const FGameplayTag BulletTag);
    
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_SetShootingInputUnreliable(const bool NewInput);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RollDysfunction(FGameplayTag PreRolledTag);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ClearDysfunction(FGameplayTag DysfunctionToClear);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ReplaceBulletWithShell(UActorComponent* BulletComponent);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_bHasShootInput() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnItemAdditionalTagChanged(const FGameplayTag Tag, const bool bAdded);
    
    UFUNCTION(BlueprintCallable)
    void OnDynamicDataUnlinked(URadiusItemDynamicData* PreviousDynamicData);
    
    UFUNCTION(BlueprintCallable)
    void OnDynamicDataLinked();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void Multicast_UpdateBulletOnClients(FGameplayTag OtherActorTypeID, int32 BulletComponentID);
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void Multicast_ShootProjectile(const FGameplayTag BulletTag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSliderLock();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOnSafety();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAcceptsAmmoType(const FGameplayTag AmmoType);
    
    UFUNCTION(BlueprintCallable)
    void InitializeMagazine();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasDysfunction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool HasAmmoInBarrel(bool& bIsShell);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorComponent* GetUnejectedBulletComponent(bool bOnlyNotShell);
    
    UFUNCTION(BlueprintCallable)
    FGameplayTag GetCurrentFireModeTag();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTag GetCurrentDysfunction();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void EndFire();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FGameplayTag EjectChamber(bool bIsManual);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool DeliverAmmoFromMagToChamber();
    
    UFUNCTION(BlueprintCallable)
    void ClearDysfunction(FGameplayTag DysfunctionToClear);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool CanShoot();
    

    // Fix for true pure virtual functions not being implemented
};

