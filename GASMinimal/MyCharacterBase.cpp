#include "MyCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "MyAbilitySystemComponent.h"
#include "MyAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffect.h"
#include "GameplayAbilitySpec.h"

AMyCharacterBase::AMyCharacterBase()
{
    PrimaryActorTick.bCanEverTick = false;

    AbilitySystemComponent = CreateDefaultSubobject<UMyAbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(false); // solo project

    AttributeSet = CreateDefaultSubobject<UMyAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AMyCharacterBase::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

void AMyCharacterBase::BeginPlay()
{
    Super::BeginPlay();

    InitializeAbilityActorInfo();
    ApplyDefaultAttributes();
    GrantStartupAbilities();
}

void AMyCharacterBase::InitializeAbilityActorInfo()
{
    AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AMyCharacterBase::ApplyDefaultAttributes() const
{
    if (!AbilitySystemComponent || !DefaultAttributesEffectClass) return;

    FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
    EffectContext.AddSourceObject(this);

    const FGameplayEffectSpecHandle SpecHandle =
        AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributesEffectClass, 1.f, EffectContext);

    if (SpecHandle.IsValid())
    {
        AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
    }
}

void AMyCharacterBase::GrantStartupAbilities()
{
    if (!AbilitySystemComponent) return;

    for (const TSubclassOf<UGameplayAbility>& AbilityClass : StartupAbilities)
    {
        if (!AbilityClass) continue;

        AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AbilityClass, 1));
    }
}
