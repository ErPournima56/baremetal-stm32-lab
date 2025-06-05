//Blinking on-board Led (PA5) on STM32F401RE without OS or HAL/LL or CMSIS
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
//volatile means dont optimize or cache this
//volatile coz its value at the address can change anytime
void Init_LED()
 {
	//Pin PA5
	RCC_AHB1ENR |= ( 1 << 0 ) ;			//(Set << pin number)	//Pheripherals wont work unless clock enabled
	//GPIOA_MODER &= ~(3 << (5 * 2));
	GPIOA_MODER |=(1 << (5 * 2));		//Each pin uses 2 bit //01 Output
	GPIOA_ODR &= ~( 1 << 5 ) ;					//ODR register stores the data to be output 	//1 high 0 Low
 }

int main(void)
{
	Init_LED() ;
   	while(1)
	{
		GPIOA_ODR ^= ( 1 << 5 )	;		//^ - Toggle
		for( volatile int i = 0; i < 1000000; i++ ) ;	//this loop executes following operations -
														//Compare i < 1000000
														//Jump if true
														//Increment i
														//Loop again
														//It takes 4 instruction cycle per iteration
														//Total Loop iteration = 1000000 * 4 = 4000000 cycles
														//STM32F401RE is 84 MHz
														//Hence, delay = total cycles / cpu_frequency
														//             = 4000000 / 84000000 = 0.0476 seconds
														//			   = 47.6 milliseconds
	}
}
