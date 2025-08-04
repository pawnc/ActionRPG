// Yan Zhu All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"


class UMangaheroGameplayAbility;
class UMangaheroAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class MANGAHERO_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(UMangaheroAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf< UMangaheroGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf< UMangaheroGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf< UMangaheroGameplayAbility>>& InAbilitiesToGive, UMangaheroAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

};
