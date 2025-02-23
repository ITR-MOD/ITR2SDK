#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GripSelectorsInterface.h"
#include "GripSelectorsController.generated.h"

UCLASS(Blueprintable)
class INTOTHERADIUS2_API AGripSelectorsController : public AActor, public IGripSelectorsInterface {
    GENERATED_BODY()
public:
    AGripSelectorsController(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

