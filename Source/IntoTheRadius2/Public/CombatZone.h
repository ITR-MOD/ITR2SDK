#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CombatZone.generated.h"

UCLASS(Abstract, Blueprintable)
class ACombatZone : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoneRadius;
    
    ACombatZone(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool IsActorInside(const AActor* Actor) const;
    
};

