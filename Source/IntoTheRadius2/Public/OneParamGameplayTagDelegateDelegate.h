#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OneParamGameplayTagDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneParamGameplayTagDelegate, FGameplayTag, Value);

