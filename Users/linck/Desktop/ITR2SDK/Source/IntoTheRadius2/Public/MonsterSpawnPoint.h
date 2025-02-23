#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpawnPoint.h"
#include "SpawnPointConfig.h"
#include "SpawnerGenerateInterface.h"
#include "MonsterSpawnPoint.generated.h"

class AActor;
class ACombatZone;
class USplineComponent;

UCLASS(Blueprintable)
class INTOTHERADIUS2_API AMonsterSpawnPoint : public ASpawnPoint, public ISpawnerGenerateInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnPointConfig PointConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsIndependentFromDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AreaRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<ACombatZone> CombatZone;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> AIPaths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* CurrentAIPath;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USplineComponent*> AttachedSplines;
    
public:
    AMonsterSpawnPoint(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void SpawnNext(const bool bSkipFirst);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpawned_BP(AActor* Spawned);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FTransform GetSpawnTransform();
    

    // Fix for true pure virtual functions not being implemented
};

