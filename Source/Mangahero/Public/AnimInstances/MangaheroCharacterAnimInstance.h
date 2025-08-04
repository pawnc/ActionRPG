// Yan Zhu All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/MangaheroBaseAnimInstance.h"
#include "MangaheroCharacterAnimInstance.generated.h"


class AMangaheroBaseCharacter;
class UCharacterMovementComponent;


/**
 * 
 */
UCLASS()
class MANGAHERO_API UMangaheroCharacterAnimInstance : public UMangaheroBaseAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override; 

	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);
	

protected:
	UPROPERTY()
	AMangaheroBaseCharacter* OwningCharacter;


	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocoMotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocoMotionData")
	bool bHasAcceleration;

};

