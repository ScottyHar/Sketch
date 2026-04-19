#include "HUD/HealthBarComponent.h"
#include "HUD/HealthBar.h"
#include "Components/ProgressBar.h"

void UHealthBarComponent::SetHealthPercent(float Percent)
{
	if (HealthBarWidget == nullptr)
	{// caching the return of a cast to UHEalth and Returns `UUserWidget*, avoid repeated casting expensive
		HealthBarWidget = Cast<UHealthBar>(GetUserWidgetObject());
	}
	//update progress bar
	if (HealthBarWidget && HealthBarWidget->HealthBar)
	{
		HealthBarWidget->HealthBar->SetPercent(Percent);
	}
}
