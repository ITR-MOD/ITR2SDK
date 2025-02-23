#include "SubtitlesBase.h"

ASubtitlesBase::ASubtitlesBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SubtitlesWidget = NULL;
    this->CameraComponent = NULL;
}

void ASubtitlesBase::ShowSave(bool bAutosave) {
}

void ASubtitlesBase::Show(TEnumAsByte<ESubtitleInstigator> SubtitleInstigator, const FText& Message, float Duration) {
}

void ASubtitlesBase::SetCameraToFollow(USceneComponent* NewCameraComponent) {
}

void ASubtitlesBase::Hide() {
}



