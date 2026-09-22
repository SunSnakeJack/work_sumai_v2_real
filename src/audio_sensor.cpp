#include "audio_sensor.h"

#include <Arduino.h>
#include <driver/i2s.h>
#include <math.h>

#include "config.h"

namespace {
constexpr i2s_port_t I2S_PORT = I2S_NUM_0;
int32_t samples[I2S_SAMPLE_BLOCK_SIZE];
bool initialized = false;
}

bool initializeAudioSensor() {
  i2s_config_t i2sConfig = {};
  i2sConfig.mode = static_cast<i2s_mode_t>(I2S_MODE_MASTER | I2S_MODE_RX);
  i2sConfig.sample_rate = I2S_SAMPLE_RATE;
  i2sConfig.bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT;
  i2sConfig.channel_format = I2S_CHANNEL_FMT_ONLY_LEFT;
  i2sConfig.communication_format = I2S_COMM_FORMAT_STAND_I2S;
  i2sConfig.intr_alloc_flags = ESP_INTR_FLAG_LEVEL1;
  i2sConfig.dma_buf_count = 4;
  i2sConfig.dma_buf_len = I2S_SAMPLE_BLOCK_SIZE;
  i2sConfig.use_apll = false;
  i2sConfig.tx_desc_auto_clear = false;
  i2sConfig.fixed_mclk = 0;

  i2s_pin_config_t pinConfig = {};
  pinConfig.mck_io_num = I2S_PIN_NO_CHANGE;
  pinConfig.bck_io_num = PIN_I2S_BCLK;
  pinConfig.ws_io_num = PIN_I2S_WS;
  pinConfig.data_out_num = I2S_PIN_NO_CHANGE;
  pinConfig.data_in_num = PIN_I2S_SD;

  if (i2s_driver_install(I2S_PORT, &i2sConfig, 0, nullptr) != ESP_OK) return false;
  if (i2s_set_pin(I2S_PORT, &pinConfig) != ESP_OK) {
    i2s_driver_uninstall(I2S_PORT);
    return false;
  }

  i2s_zero_dma_buffer(I2S_PORT);
  initialized = true;
  return true;
}

float getSoundLevel() {
  if (!initialized) return 0.0f;

  size_t bytesRead = 0;
  if (i2s_read(I2S_PORT, samples, sizeof(samples), &bytesRead, pdMS_TO_TICKS(25)) != ESP_OK) return 0.0f;

  const size_t sampleCount = bytesRead / sizeof(samples[0]);
  if (sampleCount == 0) return 0.0f;

  double mean = 0.0;
  for (size_t i = 0; i < sampleCount; ++i) mean += static_cast<double>(samples[i] >> 8);
  mean /= sampleCount;

  double sumSquares = 0.0;
  for (size_t i = 0; i < sampleCount; ++i) {
    const double centered = static_cast<double>(samples[i] >> 8) - mean;
    sumSquares += centered * centered;
  }

  return static_cast<float>(sqrt(sumSquares / sampleCount));
}

