# 🔌 STM32 Bare-metal: Blinking On-board LED (PA5)
This is a bare-metal implementation to blink the on-board LED connected to pin PA5 on the STM32F401RE (Black Pill) development board — without using HAL, LL, CMSIS, or any RTOS.

# 🧠 What This Project Covers
* Direct register-level programming of STM32F4
* No use of STM32 HAL/LL drivers or CMSIS headers
* Clock enabling and GPIO configuration through memory-mapped registers
* Basic delay generation using CPU cycle loops
* LED toggle using ODR (Output Data Register)

# 🛠️ Hardware Used
* Board: STM32F401RE (Black Pill)
* LED Pin: PA5 (On-board user LED)
