﻿#pragma once
#include "Toolkit/AssetDumping/AssetTypeSerializer.h"
#include "MediaTextureAssetSerializer.generated.h"

UCLASS(MinimalAPI)
class UMediaTextureAssetSerializer : public UAssetTypeSerializer {
	GENERATED_BODY()
public:
	virtual void SerializeAsset(TSharedRef<FSerializationContext> Context) const override;

	virtual FTopLevelAssetPath GetAssetClass() const override;
};