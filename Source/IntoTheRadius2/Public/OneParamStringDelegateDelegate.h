#pragma once
#include "CoreMinimal.h"
#include "OneParamStringDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneParamStringDelegate, const FString&, Value);

