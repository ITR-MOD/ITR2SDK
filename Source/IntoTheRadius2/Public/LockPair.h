#pragma once
#include "CoreMinimal.h"
#include "LockPair.generated.h"

class URadiusHandSocketComponent;

USTRUCT(BlueprintType)
struct FLockPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URadiusHandSocketComponent* HandSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsLocked;
    
    INTOTHERADIUS2_API FLockPair();
};

