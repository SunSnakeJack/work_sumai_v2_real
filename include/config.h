#pragma once

#include <Arduino.h>

constexpr uint8_t MPU6050_ADDRESS = 0x68;

constexpr int PIN_MPU_SDA = 4;
constexpr int PIN_MPU_SCL = 5;

constexpr int PIN_I2S_BCLK = 6;
constexpr int PIN_I2S_WS = 7;
constexpr int PIN_I2S_SD = 10;

constexpr int PIN_STATUS_LED = 0;
constexpr int PIN_SOUND_BUZZER = 1;
constexpr int PIN_MOTION_BUZZER = 3;
constexpr int PIN_MONITORING_SWITCH = 20;

constexpr uint32_t I2S_SAMPLE_RATE = 16000;
constexpr size_t I2S_SAMPLE_BLOCK_SIZE = 256;

// Placeholder only: calibrate this value with the actual INMP441 and enclosure.
constexpr float SOUND_RMS_THRESHOLD = 5000.0f;
constexpr float ACCEL_DEVIATION_THRESHOLD_G = 0.25f;
constexpr float GYRO_THRESHOLD_DPS = 35.0f;

constexpr uint8_t BUZZER_LEDC_CHANNEL = 0;
constexpr uint8_t BUZZER_LEDC_RESOLUTION_BITS = 10;
constexpr uint32_t SOUND_BUZZER_FREQUENCY_HZ = 1500;
constexpr uint32_t MOTION_BUZZER_FREQUENCY_HZ = 2200;

constexpr uint32_t SENSOR_INTERVAL_MS = 100;
constexpr uint32_t STATUS_INTERVAL_MS = 500;
constexpr uint32_t BLYNK_TELEMETRY_INTERVAL_MS = 1000;
constexpr uint32_t BLYNK_RECONNECT_INTERVAL_MS = 10000;
constexpr uint32_t BLYNK_CONNECT_SESSION_TIMEOUT_MS = 6000;
constexpr uint32_t WIFI_RECONNECT_INTERVAL_MS = 15000;
constexpr uint32_t BLYNK_EVENT_COOLDOWN_MS = 30000;

