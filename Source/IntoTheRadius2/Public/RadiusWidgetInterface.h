#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RadiusWidgetInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable)
class URadiusWidgetInterface : public UInterface {
    GENERATED_BODY()
};

class IRadiusWidgetInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetParentActor(AActor* ParentActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AActor* GetParentActor();
    
};

