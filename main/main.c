/* 
 * This file (main.c) shows how to use safe_logger.h
 *
 * This is a simple program designed to test all the 
 * LOG_XXX() functions provided by safe_logger.h 
 */

#include "safe_logger.h"

static const char *TAG = "LoggerTest";

void test_integers(void) {
    LOG_INFO(TAG, "Testing integer types at all log levels...", "\n");
    
    // Fixed-width unsigned integers
    uint8_t u8 = UINT8_MAX;
    uint16_t u16 = UINT16_MAX;
    uint32_t u32 = UINT32_MAX;
    uint64_t u64 = UINT64_MAX;

    // Test each unsigned type at each log level
    LOG_INFO(TAG, "uint8_t max", u8);
    LOG_ERROR(TAG, "uint8_t max", u8);
    LOG_WARN(TAG, "uint8_t max", u8);
    LOG_DEBUG(TAG, "uint8_t max", u8);

    LOG_INFO(TAG, "uint16_t max", u16);
    LOG_ERROR(TAG, "uint16_t max", u16);
    LOG_WARN(TAG, "uint16_t max", u16);
    LOG_DEBUG(TAG, "uint16_t max", u16);

    LOG_INFO(TAG, "uint32_t max", u32);
    LOG_ERROR(TAG, "uint32_t max", u32);
    LOG_WARN(TAG, "uint32_t max", u32);
    LOG_DEBUG(TAG, "uint32_t max", u32);

    LOG_INFO(TAG, "uint64_t max", u64);
    LOG_ERROR(TAG, "uint64_t max", u64);
    LOG_WARN(TAG, "uint64_t max", u64);
    LOG_DEBUG(TAG, "uint64_t max", u64);

    // Fixed-width signed integers
    int8_t i8 = INT8_MIN;
    int16_t i16 = INT16_MIN;
    int32_t i32 = INT32_MIN;
    int64_t i64 = INT64_MIN;

    // Test each signed type at each log level
    LOG_INFO(TAG, "int8_t min", i8);
    LOG_ERROR(TAG, "int8_t min", i8);
    LOG_WARN(TAG, "int8_t min", i8);
    LOG_DEBUG(TAG, "int8_t min", i8);

    LOG_INFO(TAG, "int16_t min", i16);
    LOG_ERROR(TAG, "int16_t min", i16);
    LOG_WARN(TAG, "int16_t min", i16);
    LOG_DEBUG(TAG, "int16_t min", i16);

    LOG_INFO(TAG, "int32_t min", i32);
    LOG_ERROR(TAG, "int32_t min", i32);
    LOG_WARN(TAG, "int32_t min", i32);
    LOG_DEBUG(TAG, "int32_t min", i32);

    LOG_INFO(TAG, "int64_t min", i64);
    LOG_ERROR(TAG, "int64_t min", i64);
    LOG_WARN(TAG, "int64_t min", i64);
    LOG_DEBUG(TAG, "int64_t min", i64);

    // Regular int
    int regular_int = -12345;
    LOG_INFO(TAG, "regular int", regular_int);
    LOG_ERROR(TAG, "regular int", regular_int);
    LOG_WARN(TAG, "regular int", regular_int);
    LOG_DEBUG(TAG, "regular int", regular_int);
}

void test_floating_point(void) {
    LOG_INFO(TAG, "Testing floating point types at all log levels...", "\n");
    
    float f = 3.14159f;
    double d = 2.7182818284590452353602874;

    LOG_INFO(TAG, "float pi", f);
    LOG_ERROR(TAG, "float pi", f);
    LOG_WARN(TAG, "float pi", f);
    LOG_DEBUG(TAG, "float pi", f);

    LOG_INFO(TAG, "double e", d);
    LOG_ERROR(TAG, "double e", d);
    LOG_WARN(TAG, "double e", d);
    LOG_DEBUG(TAG, "double e", d);
}

void test_other_types(void) {

    LOG_INFO(TAG, "Testing other types at all log levels...", "\n");
    
    // Character
    char c = 'X';
    LOG_INFO(TAG, "char", c);
    LOG_ERROR(TAG, "char", c);
    LOG_WARN(TAG, "char", c);
    LOG_DEBUG(TAG, "char", c);

    // Boolean
    bool b_true = true;
    bool b_false = false;
    LOG_INFO(TAG, "bool true", b_true);
    LOG_ERROR(TAG, "bool true", b_true);
    LOG_WARN(TAG, "bool true", b_true);
    LOG_DEBUG(TAG, "bool true", b_true);

    LOG_INFO(TAG, "bool false", b_false);
    LOG_ERROR(TAG, "bool false", b_false);
    LOG_WARN(TAG, "bool false", b_false);
    LOG_DEBUG(TAG, "bool false", b_false);

    // Strings
    char *str = "Hello";
    const char *const_str = "World";
    LOG_INFO(TAG, "char* string", str);
    LOG_ERROR(TAG, "char* string", str);
    LOG_WARN(TAG, "char* string", str);
    LOG_DEBUG(TAG, "char* string", str);

    LOG_INFO(TAG, "const char* string", const_str);
    LOG_ERROR(TAG, "const char* string", const_str);
    LOG_WARN(TAG, "const char* string", const_str);
    LOG_DEBUG(TAG, "const char* string", const_str);
}

void app_main(void)
{
    LOG_INFO(TAG, "..............Starting comprehensive logging test..............", "\n");

    // Try both ways of setting debug level
    esp_log_level_set("*", ESP_LOG_DEBUG);
    ESP_LOG_LEVEL_LOCAL(ESP_LOG_DEBUG, TAG, "Direct ESP debug test");

    LOG_INFO(TAG, "Testing integers...", "\n");
    test_integers();

    LOG_INFO(TAG, "Testing floats...", "\n");
    test_floating_point();

    LOG_INFO(TAG, "Testing other types...", "\n");
    test_other_types();

    LOG_INFO(TAG, "Logger test complete: ", "END");

    LOG_INFO(TAG, "..............Press Ctrl+] to quit the monitor..............", "");

}
