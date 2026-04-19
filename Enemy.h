#include "Enemy.generated.h"

class UHealthBarComponent;
class UAnimMontage;
class UAttributeComponent;//added the attribute component

UCLASS()
class SLASH_API AEnemy : public ACharacter, public IHitInterface
@@ -26,6 +27,9 @@ class SLASH_API AEnemy : public ACharacter, public IHitInterface
public
	//one way unreal can apply damage
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
private:
	//makes a variable to the attribute component visible in blueprint defaults and instance details the world
	UPROPERTY(VisibleAnywhere)
	UAttributeComponent* Attributes; 

	//makes a variable, visible in defaults and instance, reference to health bar widget
	UPROPERTY(VisibleAnywhere)
	// UWidgetComponent* has been placed with UHealthBarComponent	
			UHealthBarComponent* HealthBarWidget;
	/**
	* Animation montages
	*/
