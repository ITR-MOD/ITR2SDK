#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FLOpenXRExpansion.generated.h"

UCLASS(Blueprintable)
class INTOTHERADIUS2_API UFLOpenXRExpansion : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFLOpenXRExpansion();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsValveIndex();
    
};

