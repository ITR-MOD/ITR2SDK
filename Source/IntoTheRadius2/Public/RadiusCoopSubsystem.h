#pragma once
#include "CoreMinimal.h"
#include "RadiusGameInstanceSubsystem.h"
#include "RadiusCoopSubsystem.generated.h"

UCLASS(Blueprintable)
class INTOTHERADIUS2_API URadiusCoopSubsystem : public URadiusGameInstanceSubsystem {
    GENERATED_BODY()
public:
    URadiusCoopSubsystem();

    UFUNCTION(BlueprintCallable)
    EBlueprintResultSwitch SendInvite(FBPFriendInfo FriendInfo);
    
};

