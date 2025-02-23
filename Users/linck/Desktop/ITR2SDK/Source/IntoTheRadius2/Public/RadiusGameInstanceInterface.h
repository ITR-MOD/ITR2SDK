#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RadiusGameInstanceInterface.generated.h"

class AActor;
class ULevelLoadedEventTrigger;

UINTERFACE(Blueprintable)
class URadiusGameInstanceInterface : public UInterface {
    GENERATED_BODY()
};

class IRadiusGameInstanceInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ShowSplashScreen(const bool bShow);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RemoveFromSeamlessTravel(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsSplashScreenShown() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<AActor*> GetSeamlessActors();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ULevelLoadedEventTrigger* GetLevelLoadedEventTrigger();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddToSeamlessTravel(AActor* Actor);
    
};

