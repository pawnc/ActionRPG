// Yan Zhu All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/MangaheroCharacterAnimInstance.h"
#include "MangaheroHeroAnimInstance.generated.h"


class AMangaheroHeroCharacter;

/**
 * 
 */
UCLASS()
class MANGAHERO_API UMangaheroHeroAnimInstance : public UMangaheroCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);


protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	AMangaheroHeroCharacter* OwningHeroCharacter;


	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocoMotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocoMotionData")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElpasedTime;
};
