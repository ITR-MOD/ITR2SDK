﻿#pragma once
#include "Toolkit/AssetDumping/AssetTypeSerializer.h"
#include "FileMediaSourceAssetSerializer.generated.h"

UCLASS(MinimalAPI)
class UFileMediaSourceAssetSerializer : public UAssetTypeSerializer {
	GENERATED_BODY()
public:
	virtual void SerializeAsset(TSharedRef<FSerializationContext> Context) const override;

	virtual FTopLevelAssetPath GetAssetClass() const override;
};