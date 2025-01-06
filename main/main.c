#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "safe_logger.h"

static const char *TAG = "LoggerTest";

void app_main(void)
{
    // Test with different types
    uint8_t sensor_id = 42;
    uint16_t adc_val = 1234;
    uint32_t timestamp = 1234567890;
    int temperature = -5;
    float voltage = 3.3f;
    const char *status = "Active";

    // Single LOG_INFO macro works for all types
    LOG_INFO(TAG, "Sensor ID", sensor_id);      // Uses LOG_UINT8 internally
    LOG_INFO(TAG, "ADC Value", adc_val);        // Uses LOG_UINT16 internally
    LOG_INFO(TAG, "Timestamp", timestamp);      // Uses LOG_UINT32 internally
    LOG_INFO(TAG, "Temperature", temperature);  // Uses LOG_INT internally
    LOG_INFO(TAG, "Voltage", voltage);         // Uses LOG_FLOAT internally
    LOG_INFO(TAG, "Status", status);           // Uses LOG_STR internally

    while(1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}