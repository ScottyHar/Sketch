#include "Enemy.generated.h"

class UAnimMontage;
class UAttributeComponent;//added the attribute component

UCLASS()
class SLASH_API AEnemy : public ACharacter, public IHitInterface
@@ -26,6 +27,9 @@ class SLASH_API AEnemy : public ACharacter, public IHitInterface

private:

	UPROPERTY(VisibleAnywhere)
	UAttributeComponent* Attributes; //makes a variable to the attribute component visible in blueprint defaults and instance details the world

	/**
	* Animation montages
	*/
