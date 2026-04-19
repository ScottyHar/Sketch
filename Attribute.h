#pragma once
#include "Coreminimal.h"
#include "Components/ActorComponent.h"
#include "Attribute.Generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLASH_API UAttributeComponent : public UActorComponent

{
	GENERATED_BODY()
public:	
	UAttributeComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
	virtual void BeginPlay() override;
private:
	// Current Health
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float Health;
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float MaxHealth;
		
};
