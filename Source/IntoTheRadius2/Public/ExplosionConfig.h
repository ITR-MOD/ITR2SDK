#pragma once
#include "CoreMinimal.h"
#include "RadiusConfigurationAssetBase.h"
#include "ExplosionConfig.generated.h"

class UPhysicalMaterial;

UCLASS(Blueprintable)
class INTOTHERADIUS2_API UExplosionConfig : public URadiusConfigurationAssetBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FullCoverDamageBonusModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinObstacleWidthToMitigateDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultMaterialDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UPhysicalMaterial*, float> MaterialDamageModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> PlayerDamageSockets;
    
    UExplosionConfig();

};

