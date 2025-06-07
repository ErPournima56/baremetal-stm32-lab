# Bare-Metal STM32F401RE: LED Toggle with Onboard Button

This project demonstrates bare-metal programming on the STM32F401RE microcontroller (NUCLEO-F401RE board) using **no RTOS**, **no HAL**, and **no CMSIS**—just direct register access.

The onboard **user push button (PC13)** toggles the **onboard LED (PA5)** each time it's pressed.

## 📌 Project Overview

- Configure **GPIOA Pin 5** as output (for LED)
- Configure **GPIOC Pin 13** as input (for button)
- Use polling in the main loop to detect button press
- Toggle LED state on each button press (with debounce)


## 🔌 Pin Configuration

| Signal       | STM32 Pin | Mode   |
|--------------|-----------|--------|
| LED (Green)  | PA5       | Output |
| Push Button  | PC13      | Input  |

## 🧠 Code Logic (main.c)

- Enable clocks for GPIOA and GPIOC
- Configure PA5 as push-pull output
- Configure PC13 as input (floating)
- Use polling to detect falling edge (button press)
- Implement simple software debounce

## 🛠️ How to Build & Flash

1. Open STM32CubeIDE
2. `File > Import > Existing Projects into Workspace`
3. Browse and select this project folder
4. Click **Build** (hammer icon)
5. Connect NUCLEO-F401RE via USB
6. Click **Run** (green play icon) to flash

## ✅ Expected Behavior

- On power-up, LED is off
- Each time the button is pressed and released, the LED toggles

### ⚠️ Notes

- Button is **active-low**: PC13 reads `0` when pressed
- This is **pure register-level C**, good for learning the internals of STM32
