#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ERadiusItemContainerType.h"
#include "ItemContainerData.generated.h"

class UObject;

USTRUCT(Atomic, BlueprintType)
struct INTOTHERADIUS2_API FItemContainerData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERadiusItemContainerType ContainerType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString InstanceID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ParentInstanceID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform ParentContainerRelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObject> ContainerObject;
    
    FItemContainerData();
};

