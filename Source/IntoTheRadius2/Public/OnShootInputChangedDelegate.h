#pragma once
#include "CoreMinimal.h"
#include "OnShootInputChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShootInputChanged, bool, bHasShootInput);

