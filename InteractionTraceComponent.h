#pragma once
#include "Components/ActorComponent.h"
#include"InteractionTraceComponent.generated.h"

class AActor;
UCLASS(ClassGroup(Custom), Meta=(blueprintspawnableevent))

class YOURMODULE_API UInteractionTraceComponent :Public UActorComponent
{
  GENERATED_BODY()

public:
UInteractionTraceComponent()
virtual void BeginPlay()override;

UFUNCTION(BlueprintCallable, Category="Interaction")
void UpdateInteractionFocus();

UFUNCTION(BlueprintCallable, Category="Interaction")
void TryInteract();

protected
bool PerformInteractionTrace(FHitResult& OutHitResult) const;

void HandleFocusChanged(AActor* NewFocusedActor);

float TraceDistance = 500.f;

TEnumAsByte<ECollisionChannel>TraceChannel=ECC_Visibility;

bool bDebugTrace=false;

TObjectPtr<AActor> CurrentFocusedActor=nullptr;

TObjectPtr<AActor> LastFocusedActor=nullptr;
