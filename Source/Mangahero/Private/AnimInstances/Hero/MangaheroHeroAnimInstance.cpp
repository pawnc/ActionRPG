// Yan Zhu All Rights Reserved


#include "AnimInstances/Hero/MangaheroHeroAnimInstance.h"
#include "Character/MangaheroHeroCharacter.h"



void UMangaheroHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();  //���ø���ĺ���

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AMangaheroHeroCharacter>(OwningCharacter);
	}
}


void UMangaheroHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	
	if (bHasAcceleration)    //�����ɫ�ƶ������˳���Ϣ״̬
	{
		IdleElpasedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElpasedTime += DeltaSeconds; 
		bShouldEnterRelaxState = (IdleElpasedTime >= EnterRelaxStateThreshold);   //���ͣ��ʱ�����holdʱ�䣬������Ϣ����
	}
}
