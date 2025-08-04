// Yan Zhu All Rights Reserved


#include "Character/MangaheroBaseCharacter.h"
#include "AbilitySystem/MangaheroAbilitySystemComponent.h"
#include "AbilitySystem/MangaheroAttributeSet.h"

// Sets default values
AMangaheroBaseCharacter::AMangaheroBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;


	MangaheroAbilitySystemComponent = CreateDefaultSubobject<UMangaheroAbilitySystemComponent>(TEXT("MangaheroAbilitySystemComponent"));


	MangaheroAttributeSet = CreateDefaultSubobject<UMangaheroAttributeSet>(TEXT("MangaheroAttributeSet"));
	
}


UAbilitySystemComponent* AMangaheroBaseCharacter::GetAbilitySystemComponent() const
{
	return GetMangaheroAbilitySystemComponent();
}


void AMangaheroBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (MangaheroAbilitySystemComponent)
	{
		MangaheroAbilitySystemComponent->InitAbilityActorInfo(this, this);

		
		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forgot to assign start up data to %s"), *GetName());
	}
}



