// Yan Zhu All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"


class AMangaheroWeaponBase;

/**
 * 
 */
UCLASS()
class MANGAHERO_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Mangahero|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagtoRegister, AMangaheroWeaponBase* InWeaponToRegister, bool BRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "Mangahero|Combat")
	AMangaheroWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;
		 
	UPROPERTY(BlueprintReadWrite, Category = "Mangahero|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "Mangahero|Combat")
	AMangaheroWeaponBase* GetCharacterCurrentEquippedWeapon() const;

private:
	TMap<FGameplayTag, AMangaheroWeaponBase*> CharacterCarriedWeaponMap;
	
};
