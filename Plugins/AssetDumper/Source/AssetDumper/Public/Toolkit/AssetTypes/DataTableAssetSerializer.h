#pragma once
#include "Toolkit/AssetDumping/AssetTypeSerializer.h"
#include "DataTableAssetSerializer.generated.h"

UCLASS(MinimalAPI)
class UDataTableAssetSerializer : public UAssetTypeSerializer {
    GENERATED_BODY()
public:
    virtual void SerializeAsset(TSharedRef<FSerializationContext> Context) const override;

    virtual FTopLevelAssetPath GetAssetClass() const override;
};
