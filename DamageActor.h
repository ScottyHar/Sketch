#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageActor.generated.h"

class UBoxComponent;

UCLASS()
class YOURPROJECT_API ADamageActor : public AActor
{
    GENERATED_BODY()
    
public:    
    ADamageActor();

protected:
    virtual void BeginPlay() override;

    // 🔹 Collision box
    UPROPERTY(VisibleAnywhere, Category = "Damage")
    UBoxComponent* DamageBox;

    // 🔹 Damage amount
    UPROPERTY(EditAnywhere, Category = "Damage")
    float Damage = 20.f;

    // 🔹 Prevent repeated hits (optional)
    UPROPERTY(EditAnywhere, Category = "Damage")
    bool bDestroyOnHit = false;

    // 🔹 Track actors already hit
    UPROPERTY()
    TSet<AActor*> HitActors;

    // 🔹 Overlap handler
    UFUNCTION()
    void OnOverlap(
        UPrimitiveComponent* OverlappedComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult
    );

public:    
    virtual void Tick(float DeltaTime) override;
};
