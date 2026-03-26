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
  {
    NewFocusedActor = HitResult.GetActor():
      }
{
  if(NewFocusedActor != CurrentFocusedActor)
  {
    HandleFocusChanged(NewFocusedActor);
  }
void UInteractionTraceComponent::TryInteract()
{
  FHitResult HitResult;
  if(!PerformInteractionTrace(HitResult))
  {
    return;
  }
  // Later:
	// if (HitActor->Implements<UYourInteractionInterface>())
	// {
	//     IYourInteractionInterface::Execute_Interact(HitActor, GetOwner());
	// }

  UE_LOG("custom log channel?" , log, TEXT ("Interact hitacotr:%s"), *HitActor->GetName());
}  
  bool UInteractionTraceComponent::PerformInteractionTrace(FHItResult& OutHitResult) const
{
  const APLayerControler* PC = Cast<APlayerController>(GetOwner());
  if(!IsValid(PC)) return;
{
  FEVEctor TraceStart;
  FRotator ViewRotation:
  PC->GetPlayerViewPoint(TraceStart, ViewRotation);
  const FVector TraceEnd = TraceStart + (ViewRotation.Vector() * TraceDistance);
  FCOllisionQueryParams QueryParams;
  QUeryParams. AddIgnoredACtor(PC->GetPawn());
  const bool bHit = GetWorld()->LineTraceSingleByChannel(
  OutHitResult,
  TraceStart,
  TraceEnd,
  TraceChannel,
  QueryParams);
  if (bDebug)
  {
    const FColor LineColor = bHit? FColor::Red :FColor::Green;
    DrawDebugLine(GetWorld(),
			TraceStart,
			TraceEnd,
			LineColor,
			false,
			0.1f,
			0,
			2.f
		);

		if (bHit)
		{
			DrawDebugSphere(
				GetWorld(),
				OutHitResult.ImpactPoint,
				10.f,
				12,
				FColor::Yellow,
				false,
				0.1f
			);
		}
	}

	return bHit;
}

void UInteractionTraceComponent::HandleFocusChanged(AActor* NewFocusedActor)
{
	LastFocusedActor = CurrentFocusedActor;
	CurrentFocusedActor = NewFocusedActor;

	if (IsValid(CurrentFocusedActor))
	{
		UE_LOG(LogTemp, Log, TEXT("Focused actor: %s"), *CurrentFocusedActor->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Focus cleared"));
	}
}

    
  }
  
}
  
}
