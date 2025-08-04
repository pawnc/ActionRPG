// Yan Zhu All Rights Reserved


#include "AnimInstances/Hero/MangaheroHeroAnimInstance.h"
#include "Character/MangaheroHeroCharacter.h"



void UMangaheroHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();  //调用父类的函数

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AMangaheroHeroCharacter>(OwningCharacter);
	}
}


void UMangaheroHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	
	if (bHasAcceleration)    //如果角色移动，则退出休息状态
	{
		IdleElpasedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElpasedTime += DeltaSeconds; 
		bShouldEnterRelaxState = (IdleElpasedTime >= EnterRelaxStateThreshold);   //如果停留时间大于hold时间，进入休息动画
	}
}
