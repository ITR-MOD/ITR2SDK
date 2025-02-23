#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VRBPDatatypes.h"
#include "ItemContainerData.h"
#include "RadiusTickableWorldSubsystem.h"
#include "RadiusContainerSubsystem.generated.h"

class AActor;
class ARadiusItemBase;
class UObject;

UCLASS(Blueprintable)
class INTOTHERADIUS2_API URadiusContainerSubsystem : public URadiusTickableWorldSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FItemContainerData> InventoryContainers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, UObject*> HolstersAndHolders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EVRHand, UObject*> RelevantHandContainers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EVRHand, UObject*> RelevantHandContainersForAttachedItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EVRHand, AActor*> ItemsInHands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EVRHand, AActor*> HandToAttachedItem;
    
public:
    URadiusContainerSubsystem();

    UFUNCTION(BlueprintCallable)
    void UnregisterHolster(const FString& ContainerUid);
    
    UFUNCTION(BlueprintCallable)
    bool TryAttachItemToMostRelevantHolster(const EVRHand Hand, bool bAttachedItem);
    
    UFUNCTION(BlueprintCallable)
    void RemoveItemFromTrack(const EVRHand Hand);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAttachedItemFromTrack(const EVRHand Hand);
    
    UFUNCTION(BlueprintCallable)
    void RegisterHolster(const FString& ContainerUid, UObject* ContainerObject);
    
    UFUNCTION(BlueprintCallable)
    void PrintContainersStructure();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerContainerID(const FString& ContainerID) const;
    
    UFUNCTION(BlueprintCallable)
    FTransform GetWorldTransform(const FString& ContainerUid, const FTransform& InitialTransform);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetTopParentContainerID(const FString& ContainerID) const;
    
    UFUNCTION(BlueprintCallable)
    FItemContainerData GetOrCreateItemContainer(const FString& ContainerID, UObject* ContainerObject, const FString& ParentID, FTransform RelativeTransform, bool bUpdateContainerObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetMostRelevantContainer(const EVRHand Hand);
    
    UFUNCTION(BlueprintCallable)
    void GetItemContainerBP(const FString& ContainerID, bool& bFound, FItemContainerData& ContainerData);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<FString, FItemContainerData> GetContainers();
    
    UFUNCTION(BlueprintCallable)
    UObject* GetContainerObject(const FString& ContainerID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAllPlayerItems(AActor* Player, TArray<ARadiusItemBase*>& Items) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FString> GetAllChildContainerIDs(const FString& ParentContainerID, bool bIncludeChildren) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAttachItemToMostRelevantHolster(const EVRHand Hand, bool bAttachedItem) const;
    
    UFUNCTION(BlueprintCallable)
    void AddItemToTrack(const EVRHand Hand, AActor* Item);
    
    UFUNCTION(BlueprintCallable)
    void AddContainerToContainer(const FString& ContainerID, const FString& ParentID, FTransform RelativeTransform);
    
    UFUNCTION(BlueprintCallable)
    void AddAttachedItemToTrack(const EVRHand Hand, AActor* AttachedItem);
    
};

