// Yan Zhu All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/MangaheroGameplayAbility.h"
#include "MangaheroHeroGameplayAbility.generated.h"


class AMangaheroHeroCharacter;
class AMangaheroHeroController;

/**
 * 
 */
UCLASS()
class MANGAHERO_API UMangaheroHeroGameplayAbility : public UMangaheroGameplayAbility
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintPure, Category = "Mangahero|Ability")
	AMangaheroHeroCharacter* GetHeroCharacterFromActorInfo() ;

	UFUNCTION(BlueprintPure, Category = "Mangahero|Ability")
	AMangaheroHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Mangahero|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AMangaheroHeroCharacter> CachedMangaheroHeroCharacter;
	TWeakObjectPtr<AMangaheroHeroController> CachedMangaheroHeroController;
};
