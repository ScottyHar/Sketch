
What this gives you

This class is a shared home for:

line trace logic
debug drawing
focus tracking
interaction attempts

So instead of multiple player controllers all having copied code, they can all use this one component.

how controller would use it?

Your PlayerController becomes simpler:
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Interaction")
TObjectPtr<UInteractionTraceComponent> InteractionTraceComponent;

In constructor:
InteractionTraceComponent = CreateDefaultSubobject<UInteractionTraceComponent>(TEXT("InteractionTraceComponent"));

On interact input:
if (InteractionTraceComponent)
{
    InteractionTraceComponent->TryInteract();
}

if (InteractionTraceComponent)
{
    InteractionTraceComponent->UpdateInteractionFocus();
}
