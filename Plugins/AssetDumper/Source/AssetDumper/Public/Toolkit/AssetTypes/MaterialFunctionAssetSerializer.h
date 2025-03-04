#pragma once
#include "Toolkit/AssetDumping/AssetTypeSerializer.h"
#include "MaterialFunctionAssetSerializer.generated.h"

UCLASS(MinimalAPI)
class UMaterialFunctionAssetSerializer : public UAssetTypeSerializer {
	GENERATED_BODY()
public:
	virtual void SerializeAsset(TSharedRef<FSerializationContext> Context) const override;
	virtual FTopLevelAssetPath GetAssetClass() const override;
};