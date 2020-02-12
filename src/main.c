
/*butona basýldýginda discovery kart uzerinde bunana 4 adet ledi yakan ve sonduren program*/

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;

void GPIO_Config(void)
{

	//A portunda bulunan buton ayarlamalarýný yaptýk
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOA,&GPIO_InitStruct);


	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Speed  = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD,&GPIO_InitStruct);
}

void delay(uint32_t time)
{
	while(time--);
}

int main(void)
{
	GPIO_Config();

  while(1)
  {
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0))//butondan veri okumak icin kullanmalýyýz.if butona basýlýrsa 1 basýlmazas 0 olacak
	{
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0));
		delay(1680000);//1680000 = 100ms , 16800000 = 1 sn

		GPIO_ToggleBits(GPIOD,GPIO_Pin_All);
	}
  }
}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
