// Yan Zhu All Rights Reserved


#include "AnimInstances/MangaheroCharacterAnimInstance.h"
#include "Character/MangaheroBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UMangaheroCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AMangaheroBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UMangaheroCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter||!OwningMovementComponent)
	{
		return;
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}

