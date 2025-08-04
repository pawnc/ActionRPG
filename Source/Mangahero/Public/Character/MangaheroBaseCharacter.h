// Yan Zhu All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "MangaheroBaseCharacter.generated.h"


class UMangaheroAbilitySystemComponent;
class UMangaheroAttributeSet;
class UDataAsset_StartUpDataBase;


UCLASS()
class MANGAHERO_API AMangaheroBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMangaheroBaseCharacter();


	//~ Begin IAbilitySystemInterface Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//~ End IAbilitySystemInterface  Interface


protected:
	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UMangaheroAbilitySystemComponent* MangaheroAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UMangaheroAttributeSet* MangaheroAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

public:
	FORCEINLINE UMangaheroAbilitySystemComponent* GetMangaheroAbilitySystemComponent() const
	{
		return MangaheroAbilitySystemComponent;
	}

	FORCEINLINE UMangaheroAttributeSet* GetMangaheroAttributeSet() const
	{
		return MangaheroAttributeSet;
	}

};
