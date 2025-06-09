//Blinking on-board Led (PA5) on STM32F401RE using Systick Timer without OS or HAL/LL or CMSIS
//HAL -> Hardware Abstraction Layer
//LL -> Low Layer APIs
//CMSIS -> ARM's Hardware Abstraction Headers
//an RTOS

#include <stdint.h> 			//For fixed width integer types like uint32_t
//For baremetal, need to give addresses of hardware registers

//Define peripheral registers
#define  RCC_AHB1ENR	(*(volatile uint32_t*)0x40023830)		//enables clock for peripherals*
#define  GPIOA_MODER    (*(volatile uint32_t*)0x40020000)		//Sets the mode input / output for GPIO pins
#define GPIOA_ODR 		(*(volatile uint32_t*)0x40020014)		//Control the output value of the GPIO pins
#define STK_CTRL 	(*(volatile uint32_t*)0xE000E010)
#define STK_LOAD 	(*(volatile uint32_t*)0xE000E014)
#define STK_VAL    (*(volatile uint32_t*)0xE000E018)
#define STK_CALIB	(*(volatile uint32_t*)0xE000E01C)
//volatile means dont optimize or cache this
//volatile coz its value at the address can change anytime

#define FREQ_CLK 84000000UL

void Init_Systick()
{
	STK_LOAD = 83999 ;	//enter the start value where the timer has to start downcounting
	STK_VAL = 0 ;		// Clear current value
	STK_CTRL = 0x07 ; 		//Counter Enable = 1  //Exception Request Enable = 1
				//Clock Source Selection = Processor Clock (AHB) = 1
 	 	 	 	 //Countflag is a readable bit
}


void Init_LED()
 {
	//Pin PA5
	RCC_AHB1ENR |= ( 1 << 0 ) ;			//(Set << pin number)	//Pheripherals wont work unless clock enabled
	//GPIOA_MODER &= ~(3 << (5 * 2));
	GPIOA_MODER |=(1 << (5 * 2));		//Each pin uses 2 bit //01 Output
	GPIOA_ODR &= ~( 1 << 5 ) ;					//ODR register stores the data to be output 	//1 high 0 Low
 }

void delay_ms(uint32_t ms)
{
	int count ;
	for(count = 0 ; count < ms ; count++)
	{
		while ((STK_CTRL & (1 << 16)) == 0) ;	// Wait for COUNTFLAG (bit 16 of STK_CTRL) to become 1
												// This means the SysTick timer has counted down to 0
												// (1 << 16):
												//   This creates a bitmask like 0x00010000, which isolates bit 16
												// STK_CTRL & (1 << 16):
												//   This performs a bitwise AND to check if COUNTFLAG is set
												//   - If bit 16 is 1 → result is non-zero (true)
												//   - If bit 16 is 0 → result is 0 (false)
												// So the expression checks whether the COUNTFLAG is still 0

												// while ((STK_CTRL & (1 << 16)) == 0);
												//   - Keeps looping (doing nothing) as long as COUNTFLAG is 0
												//   - Exits loop once COUNTFLAG becomes 1
												//   - Note: Reading COUNTFLAG automatically clears it (auto-reset bit)
	}
}
int main(void)
{
	Init_Systick() ;
	Init_LED() ;
   	while(1)
	{
		GPIOA_ODR ^= ( 1 << 5 )	;		//^ - Toggle
		delay_ms(60000) ;		//60000 ms = 60 seconds
	}
}
