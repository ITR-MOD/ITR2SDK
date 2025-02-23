#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "ItemContainerInterface.h"
#include "RadiusHolder.generated.h"

class URadiusItemDynamicData;

UCLASS(Abstract, Blueprintable)
class INTOTHERADIUS2_API ARadiusHolder : public AActor, public IItemContainerInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyOwnerCanInteract;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AllowedGripTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreventCollisionWithAttachedItem;
    
    ARadiusHolder(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void SpawnSavedItems();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDataUnlinking(URadiusItemDynamicData* PreviousDynamicData);
    
public:
    UFUNCTION(BlueprintCallable)
    void InitializeContainer_Internal();
    
private:
    UFUNCTION(BlueprintCallable)
    void Continue_SpawnSavedItems(AActor* ItemActor);
    

    // Fix for true pure virtual functions not being implemented
};

