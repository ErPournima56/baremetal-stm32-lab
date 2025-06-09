# STM32F401RE Bare-Metal LED Blink (SysTick Timer)

This project demonstrates how to blink the on-board LED (PA5) on the STM32F401RE microcontroller using the **SysTick timer**, without using **HAL**, **LL**, **CMSIS**, or an **RTOS**.

## Project Objective

- Blink the on-board LED (PA5) once every 60 seconds
- Use **SysTick timer** for precise delays
- Avoid using STM32 HAL, LL, or any high-level libraries
- Work close to the hardware using **bare-metal coding principles**

## Microcontroller & Setup

- **MCU**: STM32F401RE (ARM Cortex-M4 @ 84 MHz)
- **Board**: Nucleo-F401RE
- **LED Pin**: `PA5` (default user LED)
- **Clock Source**: Internal system clock at 84 MHz
- **Tools**: STM32CubeIDE, ST-Link debugger

## What Is SysTick?

**SysTick** is a 24-bit **system timer** included in every ARM Cortex-M core.

- It can generate **interrupts at regular intervals**
- Typically used for:
  - Operating system ticks
  - Time delays
  - Task scheduling

In this project, SysTick is configured to **generate an interrupt every 1 millisecond**. We then use a simple loop to wait for 60,000 ticks = **60 seconds delay**.

## Hardware

- **MCU**: STM32F401RE (Cortex-M4)
- **Board**: [Nucleo-F401RE](https://www.st.com/en/evaluation-tools/nucleo-f401re.html)
- **LED Pin**: On-board LED on `GPIOA Pin 5` (PA5)
- **Clock**: Internal 84 MHz system clock

## 🛠️ Tools

- **IDE**: STM32CubeIDE
- **Compiler**: Arm GCC
- **Debugger**: ST-Link

# What It Does
- Initializes SysTick to generate a 1 ms delay
- Toggles the on-board LED every 60 seconds
- All done without HAL, CMSIS, or RTOS — using only direct register access

# Reference Docs
* RM0368 - STM32F401 Reference Manual
* PM0214 - Cortex-M4 Programming Manual
* STM32F401RE Datasheet
