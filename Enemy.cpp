#include "Slash/DebugMacros.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
//access the attribute component which is an UActorComponent
#include "Components/AttributeComponent.h"
//access the widgetcomponent
// this has been replaced created a custom Health bar component #include"Components/WidgetComponent.h"
#include "HUD/HealthBarComponent.h"
AEnemy::AEnemy()
{
@@ -17,6 +18,8 @@ AEnemy::AEnemy()
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetMesh()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
    
//attribute component is created in the constructor for AEnemy
	Attributes = CreateDefaultSubobject<UAttributeComponent>(TEXT("Attributes")); 
	
	//impliment the health bar widget which is UWidgetComponent class, creates a subobject and sets attachment to root component
HealthBarWidget = CreateDefaultSubobject<UHealthBarComponent>(TEXT("HealthBar"));
		
		HealthBarWidget->SetupAttachment(GetRootComponent());

		void AEnemy::BeginPlay()
{
	Super::BeginPlay();
//on begin play if we have a healthbarwidget then setpercent to fixed value 1.f
	if (HealthBarWidget)
	{
		HealthBarWidget->SetHealthPercent(1.f);
	}
}
		
}
