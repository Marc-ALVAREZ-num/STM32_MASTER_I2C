# Generic I2C master using STM32F429

The aim of this project is to create a generic I2C master with the device STM32F429. I use the board STM32F429-disc1 discovery kit. 
The IDE used is STM32CubeIDE.

Using this IDE the following header are automatically created :
  - stm32f4xx_hal_conf.h
  - stm32f4xx_it.h

Les fichiers sources crées automatiquement aussi :
  - stm32f4xx_hal_msp.c
  - stm32f4xx_hal_timebase_tim.c
  - stm32f4xx_it.c
  - syscalls.c
  - sysmem.c
  - system_stm32f4xx.c

De même nous utilisons le driver :
  - STM32F4xx_HAL_Driver
  - CMSIS

## Setup CubeIDE

Voir tuto [ici](docs/STM32CubeIDE_tuto.md)
