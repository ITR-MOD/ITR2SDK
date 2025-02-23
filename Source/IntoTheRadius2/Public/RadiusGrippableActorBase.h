#pragma once
#include "CoreMinimal.h"
#include "Engine/ReplicatedState.h"
#include "Grippables/GrippableActor.h"
#include "OnDistanceGripChangedDelegate.h"
#include "RadiusItemDelegateOnHolsteredDelegate.h"
#include "RadiusItemInterface.h"
#include "RadiusPooledObjectInterface.h"
#include "RadiusGrippableActorBase.generated.h"

class UMeshComponent;
class USkeletalMeshComponent;
class UStaticMeshComponent;
class USyncTransformComponent;

UCLASS(Blueprintable)
class INTOTHERADIUS2_API ARadiusGrippableActorBase : public AGrippableActor, public IRadiusItemInterface, public IRadiusPooledObjectInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDistanceGripChanged OnDistanceGripChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRadiusItemDelegateOnHolstered OnItemHolstered;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRadiusItemDelegateOnHolstered OnItemRemovedFromHolster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USyncTransformComponent* SyncTransfromComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UMeshComponent*, FName> CachedCollisions;
    
public:
    ARadiusGrippableActorBase(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartFloating();
    
protected:
    UFUNCTION(Server, Unreliable)
    void ServerRepMovement(const FRepMovement& InMovement);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerReleaseOwnership();
    
    UFUNCTION(BlueprintCallable)
    bool PollSmoothRemove();
    
    UFUNCTION(BlueprintCallable)
    bool PollSendRepMovement();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UStaticMeshComponent* GetStaticMeshComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USkeletalMeshComponent* GetSkeletalMeshComponent() const;
    

    // Fix for true pure virtual functions not being implemented
};

