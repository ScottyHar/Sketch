#include "DamageActor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

ADamageActor::ADamageActor()
{
    PrimaryActorTick.bCanEverTick = false;

    // Create collision box
    DamageBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageBox"));
    RootComponent = DamageBox;

    // Collision setup
    DamageBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    DamageBox->SetCollisionObjectType(ECC_WorldDynamic);
    DamageBox->SetCollisionResponseToAllChannels(ECR_Ignore);
    DamageBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void ADamageActor::BeginPlay()
{
    Super::BeginPlay();

    // Bind overlap
    if (DamageBox)
    {
        DamageBox->OnComponentBeginOverlap.AddDynamic(this, &ADamageActor::OnOverlap);
    }
}

void ADamageActor::OnOverlap(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (!OtherActor || OtherActor == this) return;

    // Prevent hitting same actor multiple times
    if (HitActors.Contains(OtherActor)) return;

    HitActors.Add(OtherActor);

    // Apply damage
    UGameplayStatics::ApplyDamage(
        OtherActor,
        Damage,
        GetInstigatorController(),   // optional
        this,                        // damage causer
        UDamageType::StaticClass()
    );

    // Optional: destroy after first hit
    if (bDestroyOnHit)
    {
        Destroy();
    }
}

void ADamageActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
