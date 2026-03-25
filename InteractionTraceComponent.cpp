#include "InteractionTraceComponent.h"
#include "GameFramework/PlayerController"
#include "Engine/World.h"

UInteractionTraceComponent::UInteractionTraceComponent()
{
PrimaryComponentTick.bCanEverTick = false;  
}

void UInteractionTraceComponent::BeginPlay()
{

  Super::BeginPlay();
}

void UInteractionTraceComponent::UpdateInteractionFocus()
{
  FHitResult HitResult;
  AActor* NewFocusedActor = nullptr:
  if(PerformInteractionTrace(HitResult))
    
  
}
