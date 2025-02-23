#include "RadiusCoopSubsystem.h"
#include "BlueprintDataDefinitions.h"

URadiusCoopSubsystem::URadiusCoopSubsystem() {
}

EBlueprintResultSwitch URadiusCoopSubsystem::SendInvite(FBPFriendInfo FriendInfo) {
    return EBlueprintResultSwitch::OnSuccess;
}


