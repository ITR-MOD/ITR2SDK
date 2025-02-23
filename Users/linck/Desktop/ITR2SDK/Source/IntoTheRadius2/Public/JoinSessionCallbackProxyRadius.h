#pragma once
#include "CoreMinimal.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "FindSessionsCallbackProxy.h"
#include "JoinSessionCallbackProxyRadius.generated.h"

class UJoinSessionCallbackProxyRadius;
class UObject;

UCLASS(Blueprintable, MinimalAPI)
class UJoinSessionCallbackProxyRadius : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnFailure;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
public:
    UJoinSessionCallbackProxyRadius();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UJoinSessionCallbackProxyRadius* JoinRadiusGame(UObject* NewWorldContextObject, const FBlueprintSessionResult& SessionInfo, bool bShowLoadingScreen);
    
};

