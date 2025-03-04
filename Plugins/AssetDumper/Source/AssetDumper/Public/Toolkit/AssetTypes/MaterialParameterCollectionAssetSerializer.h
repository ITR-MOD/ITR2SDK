#pragma once
#include "Toolkit/AssetDumping/AssetTypeSerializer.h"
#include "MaterialParameterCollectionAssetSerializer.generated.h"

UCLASS(MinimalAPI)
class UMaterialParameterCollectionAssetSerializer : public UAssetTypeSerializer {
    GENERATED_BODY()
public:
    virtual void SerializeAsset(TSharedRef<FSerializationContext> Context) const override;

    virtual FTopLevelAssetPath GetAssetClass() const override;
};
