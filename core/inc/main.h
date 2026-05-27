#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

void Error_Handler(void);

#define LED_GREEN_Pin GPIO_PIN_1
#define LED_GREEN_GPIO_Port GPIOA

#define LED_YELLOW_Pin GPIO_PIN_2
#define LED_YELLOW_GPIO_Port GPIOA

#define LED_RED_Pin GPIO_PIN_3
#define LED_RED_GPIO_Port GPIOA

#define BUZZER_Pin GPIO_PIN_4
#define BUZZER_GPIO_Port GPIOA

#define BUTTON_CALIB_Pin GPIO_PIN_0
#define BUTTON_CALIB_GPIO_Port GPIOB

#ifdef __cplusplus
}
#endif

#endif