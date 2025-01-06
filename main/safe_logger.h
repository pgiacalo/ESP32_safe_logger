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

// Floating point types
static inline void log_float(const char* tag, const char* msg, float val) {
    ESP_LOGI(tag, "%s: %.6f", msg, (double)val);
}

static inline void log_double(const char* tag, const char* msg, double val) {
    ESP_LOGI(tag, "%s: %.12f", msg, val);
}

// Character types
static inline void log_char(const char* tag, const char* msg, char val) {
    ESP_LOGI(tag, "%s: %c", msg, val);
}

// String types
static inline void log_str(const char* tag, const char* msg, const char* val) {
    ESP_LOGI(tag, "%s: %s", msg, val);
}

// Boolean type
static inline void log_bool(const char* tag, const char* msg, bool val) {
    ESP_LOGI(tag, "%s: %s", msg, val ? "true" : "false");
}

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

    