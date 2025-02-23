#include "FLHelpers.h"

UFLHelpers::UFLHelpers() {
}

bool UFLHelpers::TagsArrayContains(const TArray<FGameplayTag>& TagsArray, const FGameplayTag Tag, const bool bExactMatch) {
    return false;
}

void UFLHelpers::StopWidgetSound(UUserWidget* Widget, EBlueprintResultSwitch& Result) {
}

TArray<int32> UFLHelpers::SortIntArray(TArray<int32> inArray) {
    return TArray<int32>();
}

void UFLHelpers::SetUseAsOccluder(UPrimitiveComponent* PrimitiveComponent, const bool bSet) {
}

void UFLHelpers::SetTriggers(const UObject* WorldContextObject, const TArray<FGameplayTag>& Triggers, const bool bSet) {
}

FVector UFLHelpers::RoundVector(const FVector Vector, const int32 Divider) {
    return FVector{};
}

void UFLHelpers::RadiusLogStacks(const UObject* WorldContextObject, const FString& Message) {
}

void UFLHelpers::RadiusLog(const UObject* WorldContextObject, const FString& Message, const TEnumAsByte<ELogTypeBP> LogLevelType) {
}

void UFLHelpers::PlayWidgetSound(UUserWidget* Widget, const USoundBase* Sound, EBlueprintResultSwitch& Result) {
}

bool UFLHelpers::IsWidgetUnderWidget(const UWidget* WidgetUpper, const UWidget* WidgetBelow) {
    return false;
}

bool UFLHelpers::IsWidgetUnderCenterOfAnotherWidget(const UWidget* Widget, const UWidget* WidgetWithCenter) {
    return false;
}

bool UFLHelpers::IsValidLevelTag(const UObject* WorldContextObject, const FGameplayTag LevelTag) {
    return false;
}

bool UFLHelpers::IsStandalone(const UObject* WorldContextObject) {
    return false;
}

bool UFLHelpers::IsScrolledToWidget(const UWidget* WidgetObject, const UWidget* WidgetTargetObject, float CurrentScroll, const float Offset) {
    return false;
}

bool UFLHelpers::IsNetIdEquals(const FUniqueNetIdRepl& A, const FUniqueNetIdRepl& B) {
    return false;
}

bool UFLHelpers::IsInTutorial(const UObject* WorldContextObject) {
    return false;
}

bool UFLHelpers::IsInMainMenu(const UObject* WorldContextObject) {
    return false;
}

bool UFLHelpers::IsInCoop(const UObject* WorldContextObject) {
    return false;
}

bool UFLHelpers::IsHostPlayerState(const APlayerState* PlayerStateToCheck) {
    return false;
}

bool UFLHelpers::IsClient(const UObject* WorldContextObject) {
    return false;
}

bool UFLHelpers::IsAllPlayersInRange(const AActor* Actor, const float RangeDistance) {
    return false;
}

bool UFLHelpers::IsActorProtectedFromDamage(const AActor* Target, EDamageCategory DamageCategory) {
    return false;
}

bool UFLHelpers::IsActorLocallyOwned(const AActor* Actor) {
    return false;
}

bool UFLHelpers::HasAnyParentWithCapacity(UObject* Container) {
    return false;
}

FVector2f UFLHelpers::GetPosition(const UWidget* TargetWidget) {
    return FVector2f{};
}

AActor* UFLHelpers::GetOwnerActor(UUserWidget* Widget, EBlueprintResultSwitch& Result) {
    return NULL;
}

TArray<UObject*> UFLHelpers::GetObjectReferences(UObject* Obj) {
    return TArray<UObject*>();
}

TArray<FGameplayTag> UFLHelpers::GetNumericalTags(const UObject* WorldContextObject, const int32 NumberOfTags) {
    return TArray<FGameplayTag>();
}

APlayerController* UFLHelpers::GetLocalPlayerController(const UObject* WorldContextObject) {
    return NULL;
}

FGameplayTag UFLHelpers::GetLevelTagFromGateTag(const UObject* WorldContextObject, const FGameplayTag GateTag) {
    return FGameplayTag{};
}

FString UFLHelpers::GetHandHolsterName(UGripMotionControllerComponent* Controller) {
    return TEXT("");
}

EVRHand UFLHelpers::GetHandByController(UGripMotionControllerComponent* Controller) {
    return EVRHand::Left;
}

FGameplayTag UFLHelpers::GetFireModeFromTags(const UObject* WorldContextObject, const TArray<FGameplayTag>& Tags) {
    return FGameplayTag{};
}

FGameplayTag UFLHelpers::GetDysfunctionFromTags(const UObject* WorldContextObject, const TArray<FGameplayTag>& Tags) {
    return FGameplayTag{};
}

bool UFLHelpers::GetDifficultyOptionFromDifficultyConfigByTag(const FGameplayTag OptionTag, const FDifficultyConfigFloat DifficultyConfig, FDifficultyOptionFloat& OutOption) {
    return false;
}

bool UFLHelpers::GetDifficultyOptionFromDifficultyConfigByFloat(const float OptionTag, const FDifficultyConfigFloat DifficultyConfig, FDifficultyOptionFloat& OutOption) {
    return false;
}

FText UFLHelpers::GetCurrentFireModeName(const UObject* WorldContextObject, const URadiusItemDynamicData* DynamicData) {
    return FText::GetEmpty();
}

float UFLHelpers::GetAngleBetweenAngles(float A, float B) {
    return 0.0f;
}

FText UFLHelpers::GetAmmoTypeName(const UObject* WorldContextObject, const FGameplayTag& AmmoTypeTag) {
    return FText::GetEmpty();
}

FText UFLHelpers::GetAmmoCaliberName(const UObject* WorldContextObject, const FGameplayTag& AmmoTag) {
    return FText::GetEmpty();
}

TArray<APawn*> UFLHelpers::GetAllPlayerPawns(const UObject* WorldContextObject) {
    return TArray<APawn*>();
}

FVector2f UFLHelpers::GetAbsolutePositionAtPosition(const UWidget* TargetWidget) {
    return FVector2f{};
}

FVector2f UFLHelpers::GetAbsolutePosition(const UWidget* TargetWidget) {
    return FVector2f{};
}

FString UFLHelpers::GenerateUid(const FString& Prefix) {
    return TEXT("");
}

void UFLHelpers::CheckScrollForButtons(UScrollBox* CurrentScrollBox, TMap<UWidget*, int32> TitleWidgetToCategoryButtonIndex, TMap<UWidget*, UScrollBox*> TitleWidgetToParentScrollBox, bool& IsLastTitleFounded, int32& ButtonIndexToActivate) {
}

bool UFLHelpers::CheckConditions(const FConditionsList& Conditions) {
    return false;
}

bool UFLHelpers::CanPutItemInContainerWithoutOverweight(AActor* ContainerParentActor, AActor* Item) {
    return false;
}

bool UFLHelpers::AddTransformArrayToTable(UDataTable* DataTable, const FName RowName, const TArray<FTransform>& Transforms) {
    return false;
}


