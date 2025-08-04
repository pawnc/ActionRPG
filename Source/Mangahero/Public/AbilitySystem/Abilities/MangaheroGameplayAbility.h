// Yan Zhu All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MangaheroGameplayAbility.generated.h"

class UMangaheroAbilitySystemComponent;
class UPawnCombatComponent;

UENUM(BlueprintType)
enum class EMangaheroAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};


/**
 * 
 */
UCLASS()
class MANGAHERO_API UMangaheroGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	//Begin Gameplay Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//End Gameplay Interface

	UPROPERTY(EditDefaultsOnly, Category = "MangaheroAbility")
	EMangaheroAbilityActivationPolicy AbilityActivationPolicy = EMangaheroAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Mangahero|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "Mangahero|Ability")
	UMangaheroAbilitySystemComponent* GetMangaheroAbilitySystemComponentFromActorInfo() const;


}; 
