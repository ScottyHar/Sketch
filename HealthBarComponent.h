
#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "HealthBarComponent.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API UHealthBarComponent : public UWidgetComponent
{
	GENERATED_BODY()
    // create a function to set health percent it will be a float named percent
	public:
	void SetHealthPercent(float Percent);

	private:
	//create pointer to UHealthBar named Health bar widget
	UPROPERTY()
	class UHealthBar* HealthBarWidget;
};
