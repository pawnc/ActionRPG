// Yan Zhu All Rights Reserved


#include "AbilitySystem/Abilities/MangaheroHeroGameplayAbility.h"
#include "Character/MangaheroHeroCharacter.h"
#include "Controllers/MangaheroHeroController.h"

AMangaheroHeroCharacter* UMangaheroHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedMangaheroHeroCharacter.IsValid())
	{
		CachedMangaheroHeroCharacter = Cast<AMangaheroHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	
	return CachedMangaheroHeroCharacter.IsValid() ? CachedMangaheroHeroCharacter.Get() : nullptr;
	
	
}

AMangaheroHeroController* UMangaheroHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedMangaheroHeroController.IsValid())
	{
		CachedMangaheroHeroController = Cast<AMangaheroHeroController>(CurrentActorInfo->PlayerController);
	}
	return CachedMangaheroHeroController.IsValid()? CachedMangaheroHeroController.Get() : nullptr;
}

UHeroCombatComponent* UMangaheroHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
