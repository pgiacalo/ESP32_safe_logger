/*
This file is an attempt to fix the annoying PRIx compiler type problem that often occurs when logging.
To avoid these probems, call the following functions provided herein, rather than the ESP_LOGx functions:

     LOG_INFO(), LOG_WARN, LOG_ERROR, LOG_DEBUG

Note that maximum logging level is set at compile time, based on the Log Level settings via idf.py menuconfig
Note the values of the following settings in sdkconfig
    CONFIG_LOG_DEFAULT_LEVEL_VERBOSE=y
    CONFIG_LOG_DEFAULT_LEVEL=5
    CONFIG_LOG_MAXIMUM_EQUALS_DEFAULT=y
    CONFIG_LOG_MAXIMUM_LEVEL=5 

The runtime logging level can be changed within the code by calling: 

    esp_log_level_set()

However, once again, the actual maximum runtime logging level remains controlled by the settings provided via menuconfig. 

ESP LOG LEVEL   (#)     Meaning
-------------   ---     -------
ESP_LOG_NONE    (0)     Completely disables all logging.
ESP_LOG_ERROR   (1)     Logs only critical errors.
ESP_LOG_WARN    (2)     Logs warnings and errors.
ESP_LOG_INFO    (3)     Logs general informational messages, warnings, and errors.
ESP_LOG_DEBUG   (4)     Logs debug messages along with all higher levels.
ESP_LOG_VERBOSE (5)     Logs the most detailed information, suitable for in-depth debugging.

For example:

    esp_log_level_set("*", ESP_LOG_DEBUG);          // Sets all log messages to DEBUG or those more urgent
    esp_log_level_set("MY_TAG", ESP_LOG_INFO);      // Sets MY_TAG log messages to INFO or those more urgent

How the Levels Work:

    Messages with a level equal to or more urgent than the currently level are output.

*/

#pragma once

#include "esp_log.h"
#include <stdint.h>
#include <stdbool.h>

// Fixed-width integers
static inline void log_uint8(const char* tag, const char* msg, uint8_t val) {
    ESP_LOGI(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void log_uint16(const char* tag, const char* msg, uint16_t val) {
    ESP_LOGI(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void log_uint32(const char* tag, const char* msg, uint32_t val) {
    ESP_LOGI(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void log_uint64(const char* tag, const char* msg, uint64_t val) {
    ESP_LOGI(tag, "%s: %llu", msg, (unsigned long long)val);
}

static inline void log_int8(const char* tag, const char* msg, int8_t val) {
    ESP_LOGI(tag, "%s: %d", msg, (int)val);
}

static inline void log_int16(const char* tag, const char* msg, int16_t val) {
    ESP_LOGI(tag, "%s: %d", msg, (int)val);
}

static inline void log_int32(const char* tag, const char* msg, int32_t val) {
    ESP_LOGI(tag, "%s: %d", msg, (int)val);
}

static inline void log_int64(const char* tag, const char* msg, int64_t val) {
    ESP_LOGI(tag, "%s: %lld", msg, (long long)val);
}

static inline void log_int(const char* tag, const char* msg, int val) {
    ESP_LOGI(tag, "%s: %d", msg, val);
}

// Error variants
static inline void error_uint8(const char* tag, const char* msg, uint8_t val) {
    ESP_LOGE(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void error_uint16(const char* tag, const char* msg, uint16_t val) {
    ESP_LOGE(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void error_uint32(const char* tag, const char* msg, uint32_t val) {
    ESP_LOGE(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void error_uint64(const char* tag, const char* msg, uint64_t val) {
    ESP_LOGE(tag, "%s: %llu", msg, (unsigned long long)val);
}

static inline void error_int8(const char* tag, const char* msg, int8_t val) {
    ESP_LOGE(tag, "%s: %d", msg, (int)val);
}

static inline void error_int16(const char* tag, const char* msg, int16_t val) {
    ESP_LOGE(tag, "%s: %d", msg, (int)val);
}

static inline void error_int32(const char* tag, const char* msg, int32_t val) {
    ESP_LOGE(tag, "%s: %d", msg, (int)val);
}

static inline void error_int64(const char* tag, const char* msg, int64_t val) {
    ESP_LOGE(tag, "%s: %lld", msg, (long long)val);
}

static inline void error_int(const char* tag, const char* msg, int val) {
    ESP_LOGE(tag, "%s: %d", msg, val);
}

// Warning variants
static inline void warn_uint8(const char* tag, const char* msg, uint8_t val) {
    ESP_LOGW(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void warn_uint16(const char* tag, const char* msg, uint16_t val) {
    ESP_LOGW(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void warn_uint32(const char* tag, const char* msg, uint32_t val) {
    ESP_LOGW(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void warn_uint64(const char* tag, const char* msg, uint64_t val) {
    ESP_LOGW(tag, "%s: %llu", msg, (unsigned long long)val);
}

static inline void warn_int8(const char* tag, const char* msg, int8_t val) {
    ESP_LOGW(tag, "%s: %d", msg, (int)val);
}

static inline void warn_int16(const char* tag, const char* msg, int16_t val) {
    ESP_LOGW(tag, "%s: %d", msg, (int)val);
}

static inline void warn_int32(const char* tag, const char* msg, int32_t val) {
    ESP_LOGW(tag, "%s: %d", msg, (int)val);
}

static inline void warn_int64(const char* tag, const char* msg, int64_t val) {
    ESP_LOGW(tag, "%s: %lld", msg, (long long)val);
}

static inline void warn_int(const char* tag, const char* msg, int val) {
    ESP_LOGW(tag, "%s: %d", msg, val);
}

// Debug variants
static inline void debug_uint8(const char* tag, const char* msg, uint8_t val) {
    ESP_LOGD(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void debug_uint16(const char* tag, const char* msg, uint16_t val) {
    ESP_LOGD(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void debug_uint32(const char* tag, const char* msg, uint32_t val) {
    ESP_LOGD(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void debug_uint64(const char* tag, const char* msg, uint64_t val) {
    ESP_LOGD(tag, "%s: %llu", msg, (unsigned long long)val);
}

static inline void debug_int8(const char* tag, const char* msg, int8_t val) {
    ESP_LOGD(tag, "%s: %d", msg, (int)val);
}

static inline void debug_int16(const char* tag, const char* msg, int16_t val) {
    ESP_LOGD(tag, "%s: %d", msg, (int)val);
}

static inline void debug_int32(const char* tag, const char* msg, int32_t val) {
    ESP_LOGD(tag, "%s: %d", msg, (int)val);
}

static inline void debug_int64(const char* tag, const char* msg, int64_t val) {
    ESP_LOGD(tag, "%s: %lld", msg, (long long)val);
}

static inline void debug_int(const char* tag, const char* msg, int val) {
    ESP_LOGD(tag, "%s: %d", msg, val);
}

// Common types for all levels
static inline void log_float(const char* tag, const char* msg, float val) {
    ESP_LOGI(tag, "%s: %.6f", msg, (double)val);
}

static inline void log_double(const char* tag, const char* msg, double val) {
    ESP_LOGI(tag, "%s: %.12f", msg, val);
}

static inline void log_char(const char* tag, const char* msg, char val) {
    ESP_LOGI(tag, "%s: %c", msg, val);
}

static inline void log_str(const char* tag, const char* msg, const char* val) {
    ESP_LOGI(tag, "%s: %s", msg, val);
}

static inline void log_bool(const char* tag, const char* msg, bool val) {
    ESP_LOGI(tag, "%s: %s", msg, val ? "true" : "false");
}

static inline void error_float(const char* tag, const char* msg, float val) {
    ESP_LOGE(tag, "%s: %.6f", msg, (double)val);
}

static inline void error_double(const char* tag, const char* msg, double val) {
    ESP_LOGE(tag, "%s: %.12f", msg, val);
}

static inline void error_char(const char* tag, const char* msg, char val) {
    ESP_LOGE(tag, "%s: %c", msg, val);
}

static inline void error_str(const char* tag, const char* msg, const char* val) {
    ESP_LOGE(tag, "%s: %s", msg, val);
}

static inline void error_bool(const char* tag, const char* msg, bool val) {
    ESP_LOGE(tag, "%s: %s", msg, val ? "true" : "false");
}

static inline void warn_float(const char* tag, const char* msg, float val) {
    ESP_LOGW(tag, "%s: %.6f", msg, (double)val);
}

static inline void warn_double(const char* tag, const char* msg, double val) {
    ESP_LOGW(tag, "%s: %.12f", msg, val);
}

static inline void warn_char(const char* tag, const char* msg, char val) {
    ESP_LOGW(tag, "%s: %c", msg, val);
}

static inline void warn_str(const char* tag, const char* msg, const char* val) {
    ESP_LOGW(tag, "%s: %s", msg, val);
}

static inline void warn_bool(const char* tag, const char* msg, bool val) {
    ESP_LOGW(tag, "%s: %s", msg, val ? "true" : "false");
}

static inline void debug_float(const char* tag, const char* msg, float val) {
    ESP_LOGD(tag, "%s: %.6f", msg, (double)val);
}

static inline void debug_double(const char* tag, const char* msg, double val) {
    ESP_LOGD(tag, "%s: %.12f", msg, val);
}

static inline void debug_char(const char* tag, const char* msg, char val) {
    ESP_LOGD(tag, "%s: %c", msg, val);
}

static inline void debug_str(const char* tag, const char* msg, const char* val) {
    ESP_LOGD(tag, "%s: %s", msg, val);
}

static inline void debug_bool(const char* tag, const char* msg, bool val) {
    ESP_LOGD(tag, "%s: %s", msg, val ? "true" : "false");
}

// User-friendly macros that select the right function
#define LOG_INFO(tag, msg, val) _Generic((val), \
    uint8_t:  log_uint8, \
    uint16_t: log_uint16, \
    uint32_t: log_uint32, \
    uint64_t: log_uint64, \
    int8_t:   log_int8, \
    int16_t:  log_int16, \
    int32_t:  log_int32, \
    int64_t:  log_int64, \
    int:      log_int, \
    float:    log_float, \
    double:   log_double, \
    char:     log_char, \
    bool:     log_bool, \
    char*:    log_str, \
    const char*: log_str)(tag, msg, val)

#define LOG_ERROR(tag, msg, val) _Generic((val), \
    uint8_t:  error_uint8, \
    uint16_t: error_uint16, \
    uint32_t: error_uint32, \
    uint64_t: error_uint64, \
    int8_t:   error_int8, \
    int16_t:  error_int16, \
    int32_t:  error_int32, \
    int64_t:  error_int64, \
    int:      error_int, \
    float:    error_float, \
    double:   error_double, \
    char:     error_char, \
    bool:     error_bool, \
    char*:    error_str, \
    const char*: error_str)(tag, msg, val)

#define LOG_WARN(tag, msg, val) _Generic((val), \
    uint8_t:  warn_uint8, \
    uint16_t: warn_uint16, \
    uint32_t: warn_uint32, \
    uint64_t: warn_uint64, \
    int8_t:   warn_int8, \
    int16_t:  warn_int16, \
    int32_t:  warn_int32, \
    int64_t:  warn_int64, \
    int:      warn_int, \
    float:    warn_float, \
    double:   warn_double, \
    char:     warn_char, \
    bool:     warn_bool, \
    char*:    warn_str, \
    const char*: warn_str)(tag, msg, val)

#define LOG_DEBUG(tag, msg, val) _Generic((val), \
    uint8_t:  debug_uint8, \
    uint16_t: debug_uint16, \
    uint32_t: debug_uint32, \
    uint64_t: debug_uint64, \
    int8_t:   debug_int8, \
    int16_t:  debug_int16, \
    int32_t:  debug_int32, \
    int64_t:  debug_int64, \
    int:      debug_int, \
    float:    debug_float, \
    double:   debug_double, \
    char:     debug_char, \
    bool:     debug_bool, \
    char*:    debug_str, \
    const char*: debug_str)(tag, msg, val)