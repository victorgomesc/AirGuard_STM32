#include "air_quality.h"

void AirQuality_Init(AirQualityConfig *config)
{
    config->baseValue = 400;
    config->goodLimit = 600;
    config->moderateLimit = 850;
}

void AirQuality_Calibrate(AirQualityConfig *config, uint32_t adcValue)
{
    config->baseValue = adcValue;
    config->goodLimit = adcValue + 200;
    config->moderateLimit = adcValue + 450;
}

AirQualityStatus AirQuality_GetStatus(uint32_t adcValue, AirQualityConfig *config)
{
    if (adcValue <= config->goodLimit)
    {
        return AIR_GOOD;
    }
    else if (adcValue <= config->moderateLimit)
    {
        return AIR_MODERATE;
    }
    else
    {
        return AIR_BAD;
    }
}

const char* AirQuality_GetStatusText(AirQualityStatus status)
{
    switch (status)
    {
        case AIR_GOOD:
            return "AR BOM";

        case AIR_MODERATE:
            return "AR MODERADO";

        case AIR_BAD:
            return "AR RUIM";

        default:
            return "DESCONHECIDO";
    }
}