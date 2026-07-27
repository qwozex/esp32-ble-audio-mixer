#ifndef CONFIG_H
#define CONFIG_H

// --- Device Settings ---
#define DEVICE_NAME "ESP32-AudioMixer"

// --- Hardware Pins (ADC1 only to support Wi-Fi/BLE concurrently) ---
const int FADER_PINS[4] = {36, 39, 34, 35};
const int NUM_FADERS = 4;

// --- Signal Processing ---
#define FILTER_ALPHA 0.15f  // Smoothing factor for Exponential Moving Average (0.01 - 1.0)
#define HYSTERESIS 16       // Threshold to discard minor ADC noise (0-4095 scale)

#endif // CONFIG_H