
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"
/**
 * 
 */
UCLASS()
class SLASH_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()
public:
	//variable pointing to progress bar called Health, meta tag links to the widget1717
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthBar;
};
