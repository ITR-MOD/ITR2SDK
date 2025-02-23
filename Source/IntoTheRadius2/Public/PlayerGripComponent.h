#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "VRBPDatatypes.h"
#include "GripOverlap.h"
#include "PlayerGripComponent.generated.h"

class AActor;
class ACharacter;
class ARadiusGrippableActorBase;
class UGripMotionControllerComponent;
class UPrimitiveComponent;
class URadiusHandSocketComponent;
class USphereComponent;
class UVRCharacterMovementComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class INTOTHERADIUS2_API UPlayerGripComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnClimbingInitiated, EVRHand, Hand, UPrimitiveComponent*, GrippedObject, FTransform, RelativeTransform);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClimbingEnded);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGripOverlap GripOverlapLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGripOverlap GripOverlapRight;
    
private:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TMap<EVRHand, TWeakObjectPtr<UGripMotionControllerComponent>> Controllers;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TMap<EVRHand, TWeakObjectPtr<USphereComponent>> GrabSpheres;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URadiusHandSocketComponent*> LeftHandLockedSockets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URadiusHandSocketComponent*> RightHandLockedSockets;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UVRCharacterMovementComponent> MovementComponent;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnClimbingInitiated OnClimbingInitiated;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnClimbingEnded OnClimbingEnded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsHandClimbing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVRHand ClimbingHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> ClimbingObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform ClimbingGripTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsClimbingObjectRelative;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DefaultGripTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DefaultSecondaryGripTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DefaultDropTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DefaultSecondaryDropTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceOverlapOnlyGripChecks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EObjectTypeQuery>> CollisionToCheckDuringGrip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EObjectTypeQuery>> CollisionToCheckForDistantGrip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EObjectTypeQuery>> CollisionToCheckDuringReverseLineTrace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlwaysAllowClimbing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GripTraceLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLimitMaxThrowVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumThrowingVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MassScalerMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThrowingMassMaximum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bScaleVelocityByMass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSampleGripVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseControllerVelocityOnRelease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableMovement;
    
public:
    UPlayerGripComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool UnlockGrip(EVRHand Hand, ARadiusGrippableActorBase* GripActor, bool bUseFakeGrip);
    
    UFUNCTION(BlueprintCallable)
    void StopDistanceGrip(EVRHand Hand);
    
    UFUNCTION(BlueprintCallable)
    void StartDistanceGrip(UPrimitiveComponent* Primitive, EVRHand Hand, FVector GripRelativeLocation, FQuat GripRelativeRotation);
    
    UFUNCTION(BlueprintCallable)
    void SetupHand(EVRHand Hand, UGripMotionControllerComponent* Controller, USphereComponent* GrabSphere);
    
    UFUNCTION(BlueprintCallable)
    void SetHoldingX(bool bHolding);
    
    UFUNCTION(BlueprintCallable)
    void SetHoldingA(bool bHolding);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerRequestOwnership(EVRHand Hand, UPrimitiveComponent* Target);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool LockGrip(EVRHand Hand, ARadiusGrippableActorBase* GripActor, URadiusHandSocketComponent*& HandSocket, bool bUseFakeGrip);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGripLocked(EVRHand Hand, FGameplayTag GripQueryType, const URadiusHandSocketComponent* HandSocket) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAltInteraction(EVRHand Hand) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter* GetOwnerCharacter() const;
    
public:
    UFUNCTION(BlueprintCallable)
    TArray<URadiusHandSocketComponent*> GetOverlappedHandSockets(TArray<AActor*> OverlappedActors, FGameplayTagContainer GripTags, UGripMotionControllerComponent* MotionController);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USphereComponent* GetGrabSphere(EVRHand Hand);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UGripMotionControllerComponent* GetController(EVRHand Hand);
    
public:
    UFUNCTION(BlueprintCallable)
    void FindClosestGrippableHandSockets(TArray<URadiusHandSocketComponent*> InputSocketArray, TMap<FGameplayTag, URadiusHandSocketComponent*>& HandSockets, EVRHand Hand, UGripMotionControllerComponent* QueryController, FVector HandDirection, bool& bOutDistanceGrip, bool bIsDistanceGrip);
    
    UFUNCTION(BlueprintCallable)
    void FillGripOverlap(EVRHand Hand, URadiusHandSocketComponent* HandSocket, bool bIsDistanceGrip);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DropGrip(EVRHand Hand, bool bTrigger);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DistanceGripRejected(EVRHand Hand);
    
private:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientOwnershipRejected(EVRHand Hand);
    
public:
    UFUNCTION(BlueprintCallable)
    void ClearGripOverlap(EVRHand Hand);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ChangePressedGrip(EVRHand Hand, const bool bIsPressed);
    
};

