#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "EVRHand.h"
#include "ItemContainerInterface.generated.h"

class AActor;
class APawn;
class ARadiusItemBase;
class UGripMotionControllerComponent;
class UObject;
class USceneComponent;

UINTERFACE(Blueprintable)
class UItemContainerInterface : public UInterface {
    GENERATED_BODY()
};

class IItemContainerInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartHolstering(const AActor* ItemActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldChangeCollisionOnAttach();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetHighlight(bool bIsHighlight, EVRHand Hand, ARadiusItemBase* Item);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool PutItemToContainer(AActor* ItemActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PlaceInsideContainer(const FString& ParentContainerUid, const FTransform& Transform);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void NotifyAttachFailure();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsWithinDistance(float DistanceToItem, const AActor* ItemActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsSuitableByTags(const FGameplayTag& ItemTag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsEnoughWeightForItem(AActor* ItemActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsDependsWeight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsContainerValid();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsAvailable(UGripMotionControllerComponent* MotionController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InstantHolsterActor(AActor* ItemActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FTransform GetTransformRelativeToParent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetPriority();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UObject* GetParentContainerObject();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    APawn* GetItemOwningPawn();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<AActor*> GetHolstered();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FGameplayTag GetContainerTag() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FGameplayTag GetContainerSoundType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USceneComponent* GetContainerSceneComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FString GetContainerID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FGameplayTagContainer GetAllowedGripTags();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool DropHolsteredActor(AActor* ItemActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<AActor*> DropHolstered();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanBeArmored() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool AllowsInteraction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool AllowsGripping(FGameplayTagContainer GripTags, UGripMotionControllerComponent* MotionController);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddContainerToGameData();
    
};

