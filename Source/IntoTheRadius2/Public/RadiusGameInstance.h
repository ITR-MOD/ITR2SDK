#pragma once
#include "CoreMinimal.h"
#include "BlueprintDataDefinitions.h"
#include "AdvancedFriendsGameInstance.h"
#include "RadiusGameInstanceInterface.h"
#include "RadiusSplashDesc.h"
#include "Templates/SubclassOf.h"
#include "RadiusGameInstance.generated.h"

class AActor;
class ULevelLoadedEventTrigger;
class URadiusCheatSubsystem;
class URadiusGameInstanceSubsystem;

UCLASS(Blueprintable, NonTransient)
class INTOTHERADIUS2_API URadiusGameInstance : public UAdvancedFriendsGameInstance, public IRadiusGameInstanceInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRadiusSplashDesc> SplashDescriptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> SeamlessTravelActorsList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> IngameMenuClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSaveLoadTemporarilyDisabled;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULevelLoadedEventTrigger* LevelLoadedEventTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URadiusCheatSubsystem> BPRadiusCheatSubsystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URadiusGameInstanceSubsystem> BPRadiusAnalyticsSubsystem;
    
public:
    URadiusGameInstance(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnLevelLoaded();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGameStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExitGame();
    

    // Fix for true pure virtual functions not being implemented
};

