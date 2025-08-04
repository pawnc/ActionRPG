// Yan Zhu All Rights Reserved


#include "AbilitySystem/Abilities/MangaheroGameplayAbility.h"
#include "AbilitySystem/MangaheroAbilitySystemComponent.h"
#include "Components/Combat/PawnCombatComponent.h"



void UMangaheroGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == EMangaheroAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}

	}
}


void UMangaheroGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (AbilityActivationPolicy == EMangaheroAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}

	}
}

UPawnCombatComponent* UMangaheroGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
	
}

UMangaheroAbilitySystemComponent* UMangaheroGameplayAbility::GetMangaheroAbilitySystemComponentFromActorInfo() const
{
	return Cast<UMangaheroAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
	
}
