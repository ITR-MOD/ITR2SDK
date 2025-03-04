#pragma once
#include "AssetDumpProcessor.h"
#include "Slate.h"

class SAssetDumperWidget : public SCompoundWidget {
public:
	SLATE_BEGIN_ARGS(SAssetDumperWidget) {}
	SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);
protected:
	TMap<FTopLevelAssetPath, bool> AssetClassSerializationRules;
	TMap<FTopLevelAssetPath, TArray<FTopLevelAssetPath>> AdditionalAssetTypes;
	
	TSharedPtr<class SAssetRegistryViewWidget> AssetRegistryViewWidget;
	TSharedPtr<class SButton> AssetDumpButton;
	TSharedPtr<class SEditableTextBox> OutputPathText;
	FAssetDumpSettings AssetDumpSettings;

	TSharedRef<SWidget> CreateAssetTypeFilterCategory();
	TSharedRef<SWidget> CreateSettingsCategory();
	
	FReply OnBrowseOutputPathPressed();
	FReply OnAssetDumpButtonPressed();
};