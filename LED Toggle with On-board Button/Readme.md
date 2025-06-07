# Bare-Metal STM32F401RE: LED Toggle with Onboard Button

This project demonstrates bare-metal programming on the STM32F401RE microcontroller (NUCLEO-F401RE board) using **no RTOS**, **no HAL**, and **no CMSIS**—just direct register access.

The onboard **user push button (PC13)** toggles the **onboard LED (PA5)** each time it's pressed.

## 🔧 Tools Used

- **IDE**: [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
- **Microcontroller**: STM32F401RET6 (NUCLEO-F401RE board)
- **Language**: C
- **Drivers**: Bare-metal (direct register access)

## 📌 Project Overview

- Configure **GPIOA Pin 5** as output (for LED)
- Configure **GPIOC Pin 13** as input (for button)
- Use polling in the main loop to detect button press
- Toggle LED state on each button press (with debounce)

