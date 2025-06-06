# STM32 Bare-Metal Programming – No OS, No HAL

This repository contains bare-metal projects written for the **STM32F401RET6** microcontroller ( Nucleo-F401RE board ). All code runs directly on the hardware, without any operating system or external libraries like HAL or RTOS.

## 🧠 Why Bare-Metal?

- Learn how microcontrollers really work under the hood
- Gain full control over registers and peripherals
- Understand embedded concepts like memory-mapped I/O, interrupts, and USB protocols
- Avoid the overhead and abstraction layers introduced by libraries

## 📦 What Microcontroller?

- **STM32F401RET6** (ARM Cortex-M4)
- Runs at 84 MHz
- Commonly used on Nucleo development boards
- 512 KB Flash, 96 KB RAM
- Rich peripherals: GPIO, USART, I2C, SPI, USB, timers, etc.

## 🚀 What Does “Bare-Metal” Mean?

Bare-metal programming means:
- No operating system
- No hardware abstraction layers (HAL)
- No middleware or libraries
- You program **directly using registers** defined by the chip's reference manual

You control everything — initialization, configuration, main loop, and interrupt service routines.

## ⚡ Real Applications of Bare-Metal Programming

- **Low-cost embedded devices** where OS is unnecessary
- **Time-critical systems** where direct control is required
- **Medical devices**, **automotive ECUs**, **consumer electronics**
- Custom USB HID devices (like in this repo)

## 🆚 HAL vs CMSIS vs Bare-Metal

| Type    | Description |
|---------|-------------|
| **HAL** (Hardware Abstraction Layer) | High-level library from STMicroelectronics. Makes setup easier, but hides low-level details. |
| **CMSIS** (Cortex Microcontroller Software Interface Standard) | A vendor-neutral standard from ARM. Provides core definitions (like NVIC, SysTick) and some helpers. Still close to hardware. |
| **Bare-metal** | Writes directly to peripheral registers via the STM32 reference manual. |


## ❓“No OS” — What Does That Mean?

This firmware runs without an operating system like FreeRTOS or Linux. The code:
- Starts at `main()`
- Sets up hardware
- Loops forever
- Handles events using polling or interrupts

This is similar in spirit to programming **PIC18** or **AVR** microcontrollers — where you work directly with registers and there's no background task scheduler unless you build one.

## 📁 Projects Included

- `led_blink/` – Blink an onboard LED using GPIO
- `button_input/` – Read a button and control LED
- `usb_hid_keyboard/` – Send keyboard characters to PC using USB HID

## 🛠️ Build and Flash

- Toolchain: ARM GCC
- IDE: STM32CubeIDE
- Flash using ST-Link 

---

## 📚 Resources

- STM32F401 Reference Manual (RM0368)
