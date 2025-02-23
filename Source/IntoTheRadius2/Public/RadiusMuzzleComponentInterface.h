#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "RadiusMuzzleComponentInterface.generated.h"

class USceneComponent;

UINTERFACE(Blueprintable, MinimalAPI)
class URadiusMuzzleComponentInterface : public UInterface {
    GENERATED_BODY()
};

class IRadiusMuzzleComponentInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SwitchWith(USceneComponent* Other);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShootProjectile(FGameplayTag GameplayTag, bool bIsLastRound);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsSilencerMuzzle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetMuzzlePriority();
    
};

