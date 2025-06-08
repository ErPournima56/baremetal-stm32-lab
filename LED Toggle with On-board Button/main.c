//Switch onboard led PA5 using Onoboard Button PC13

#include <stdint.h>

#define RCC_AHB1ENR		(*(volatile uint32_t*)0x40023830)		//offset :30 - added at the end
#define GPIOA_MODER		(*(volatile uint32_t*)0x40020000)		//offset :0x00
#define GPIOA_ODR		(*(volatile uint32_t*)0x40020014)		//offset :0x14

#define GPIOC_MODER		(*(volatile uint32_t*)0x40020800)
#define GPIOC_IDR		(*(volatile uint32_t*)0x40020810)		//offset :0x10

#define LED_PIN		5
#define BUTTON_PIN 	13

void Init_Led()
{
	RCC_AHB1ENR |= ( 1 << 0 ) ;		//Clock enable for GPIOA

	GPIOA_MODER |= ( 1 << ( LED_PIN * 2 )) ;		//Set bit 5 to 1	//Output mode
	GPIOA_ODR &= ~( 1 << LED_PIN ) ;		//Initially led set to 0
}

void Init_Button()
{
	RCC_AHB1ENR |= ( 1 << 2 ) ;		//Clock enable for GPIOC

	GPIOC_MODER &= ~( 3 << ( BUTTON_PIN * 2 )) ;		//Input Mode
}

void Led_Display()
{
	while(1)
	{
		if(((GPIOC_IDR >> BUTTON_PIN) & 1) == 0)
		{
			GPIOA_ODR |= ( 1 << LED_PIN ) ;
			for(int i = 0; i < 1000000; i++) ;
		}
		GPIOA_ODR &= ~( 1 << LED_PIN ) ;
	}
}

int main()
{
	Init_Led() ;
	Init_Button() ;

	Led_Display() ;
	return 0 ;
}
