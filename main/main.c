#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "safe_logger.h"
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>

static const char *TAG = "LoggerTest";

void test_all_types(void) {
    // Fixed-width unsigned integers
    uint8_t u8 = UINT8_MAX;
    uint16_t u16 = UINT16_MAX;
    uint32_t u32 = UINT32_MAX;
    uint64_t u64 = UINT64_MAX;

    LOG_INFO(TAG, "uint8_t max", u8);
    LOG_INFO(TAG, "uint16_t max", u16);
    LOG_INFO(TAG, "uint32_t max", u32);
    LOG_INFO(TAG, "uint64_t max", u64);

    // Fixed-width signed integers
    int8_t i8 = INT8_MIN;
    int16_t i16 = INT16_MIN;
    int32_t i32 = INT32_MIN;
    int64_t i64 = INT64_MIN;

    LOG_INFO(TAG, "int8_t min", i8);
    LOG_INFO(TAG, "int16_t min", i16);
    LOG_INFO(TAG, "int32_t min", i32);
    LOG_INFO(TAG, "int64_t min", i64);

    // Regular int
    int regular_int = -12345;
    LOG_INFO(TAG, "regular int", regular_int);

    // Floating point
    float f = 3.14159f;
    double d = 2.7182818284590452353602874;

    LOG_INFO(TAG, "float pi", f);
    LOG_INFO(TAG, "double e", d);

    // Character
    char c = 'X';
    LOG_INFO(TAG, "char", c);

    // Boolean
    bool b_true = true;
    bool b_false = false;
    LOG_INFO(TAG, "bool true", b_true);
    LOG_INFO(TAG, "bool false", b_false);

    // Strings
    char *str = "Hello";
    const char *const_str = "World";
    LOG_INFO(TAG, "char* string", str);
    LOG_INFO(TAG, "const char* string", const_str);
}

void app_main(void)
{
    printf("Starting type test for safe logger\n");
    test_all_types();
    
    while(1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}