#include "Slash/DebugMacros.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AttributeComponent.h"

AEnemy::AEnemy()
{
@@ -17,6 +18,8 @@ AEnemy::AEnemy()
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetMesh()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
    
//attribute component is created in the constructor for AEnemy
	Attributes = CreateDefaultSubobject<UAttributeComponent>(TEXT("Attributes")); 
}
