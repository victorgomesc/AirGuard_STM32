#ifndef AIR_QUALITY_H
#define AIR_QUALITY_H

#include "main.h"

typedef enum
{
    AIR_GOOD = 0,
    AIR_MODERATE,
    AIR_BAD
} AirQualityStatus;

typedef struct
{
    uint32_t baseValue;
    uint32_t goodLimit;
    uint32_t moderateLimit;
} AirQualityConfig;

void AirQuality_Init(AirQualityConfig *config);
void AirQuality_Calibrate(AirQualityConfig *config, uint32_t adcValue);
AirQualityStatus AirQuality_GetStatus(uint32_t adcValue, AirQualityConfig *config);
const char* AirQuality_GetStatusText(AirQualityStatus status);

#endif