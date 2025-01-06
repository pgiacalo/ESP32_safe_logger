#pragma once

#include "esp_log.h"
#include <stdint.h>

// Helper functions that handle the actual logging
static inline void log_uint8(const char* tag, const char* msg, uint8_t val) {
    ESP_LOGI(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void log_uint16(const char* tag, const char* msg, uint16_t val) {
    ESP_LOGI(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void log_uint32(const char* tag, const char* msg, uint32_t val) {
    ESP_LOGI(tag, "%s: %u", msg, (unsigned int)val);
}

static inline void log_int(const char* tag, const char* msg, int val) {
    ESP_LOGI(tag, "%s: %d", msg, val);
}

static inline void log_float(const char* tag, const char* msg, float val) {
    ESP_LOGI(tag, "%s: %.2f", msg, (double)val);
}

static inline void log_str(const char* tag, const char* msg, const char* val) {
    ESP_LOGI(tag, "%s: %s", msg, val);
}

// User-friendly macro that selects the right function
#define LOG_INFO(tag, msg, val) _Generic((val), \
    uint8_t:    log_uint8, \
    uint16_t:   log_uint16, \
    uint32_t:   log_uint32, \
    int:        log_int, \
    float:      log_float, \
    char*:      log_str, \
    const char*: log_str \
    )(tag, msg, val)