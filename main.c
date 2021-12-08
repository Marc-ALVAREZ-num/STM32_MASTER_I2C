/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c3;

/* USER CODE BEGIN PV */
uint8_t telemetry_command[8]={0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};/*pointeur vers l'adresse du registre où est enregistrée la commande*/
uint8_t arm_thruster [8]= {0x05, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
uint8_t start_firing [8]= {0x05, 0x02, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
uint8_t stop_propulsion [8]= {0x05, 0x03, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
uint8_t change_operation [8]= {0x05, 0x04, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55};  // attention !!! veifier mode --> change_operation [2] = 0x01/2/3/4/5
uint8_t start_gnd_test [8]= {0x05, 0x05, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
uint8_t stop_gnd_test [8]= {0x05, 0x06, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
uint8_t reset_error [8]= {0x05, 0x0A, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
//uint8_t command[8][8]={telemetry_command,arm_thruster,start_firing,stop_propulsion,change_operation,start_gnd_test,stop_gnd_test,reset_error};

uint8_t data_receive[128];  /* pointeur vers l'adresse du registre où sera enregistrée la lecture de la télémetrie*/
uint8_t data_receive2[128];
uint8_t comparaison[128];
uint8_t status[10]={1,1,1,1,1,1,1,1,1,1};
uint8_t error_11[10]={1,1,1,1,1,1,1,1,1,1};
int valeur;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C3_Init();
  /* USER CODE BEGIN 2 */
  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), reset_error, 8, 1000);
  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), telemetry_command, 8, 1000);
  HAL_I2C_Master_Receive(&hi2c3, (0x10<<1)|0x01, data_receive, 128, 1000);
  status[0]=data_receive[8];
  error_11[0]=data_receive[11];

  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), arm_thruster, 8, 1000);
  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), telemetry_command, 8, 1000);
  HAL_I2C_Master_Receive(&hi2c3, (0x10<<1)|0x01, data_receive, 128, 1000);
  status[1]=data_receive[8];
  error_11[1]=data_receive[11];

  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), start_firing, 8, 1000);
  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), telemetry_command, 8, 1000);
  HAL_I2C_Master_Receive(&hi2c3, (0x10<<1)|0x01, data_receive, 128, 1000);
  status[2]=data_receive[8];
  error_11[2]=data_receive[11];


  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), stop_propulsion, 8, 1000);
  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), telemetry_command, 8, 1000);
  HAL_I2C_Master_Receive(&hi2c3, (0x10<<1)|0x01, data_receive, 128, 1000);
  status[3]=data_receive[8];
  error_11[3]=data_receive[11];


  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), start_gnd_test, 8, 1000);
  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), telemetry_command, 8, 1000);
  HAL_I2C_Master_Receive(&hi2c3, (0x10<<1)|0x01, data_receive, 128, 1000);
  status[4]=data_receive[8];
  error_11[4]=data_receive[11];

  //HAL_Delay(120000);
  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), telemetry_command, 8, 1000);
  HAL_I2C_Master_Receive(&hi2c3, (0x10<<1)|0x01, data_receive, 128, 1000);
  status[5]=data_receive[8];
  error_11[5]=data_receive[11];

  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), stop_gnd_test, 8, 1000);
  HAL_I2C_Master_Transmit(&hi2c3, (0x10<<1), telemetry_command, 8, 1000);
  HAL_I2C_Master_Receive(&hi2c3, (0x10<<1)|0x01, data_receive, 128, 1000);
  status[6]=data_receive[8];
  error_11[6]=data_receive[11];


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 50;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV8;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C3_Init(void)
{

  /* USER CODE BEGIN I2C3_Init 0 */

  /* USER CODE END I2C3_Init 0 */

  /* USER CODE BEGIN I2C3_Init 1 */

  /* USER CODE END I2C3_Init 1 */
  hi2c3.Instance = I2C3;
  hi2c3.Init.ClockSpeed = 100000;
  hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c3.Init.OwnAddress1 = 0;
  hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c3.Init.OwnAddress2 = 0;
  hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c3) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c3, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c3, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C3_Init 2 */

  /* USER CODE END I2C3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
int fonction_comparaison(uint8_t *data1,uint8_t *data2)
{
	int i;
	valeur=sizeof(data1);
	for (i=0;i<128;i++)
	{
		if (data1[i]!=data2[i])
		{
			comparaison[i]=data2[i];
		}
		else
		{
			comparaison[i]=i;
		}
	}
	return 0;
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
