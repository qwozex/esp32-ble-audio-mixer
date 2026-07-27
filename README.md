# 🎛️ ESP32 BLE Wireless Audio Mixer & MIDI Controller

A wireless physical audio controller and MIDI interface built with **ESP32 DevKit V1**, featuring 4 smooth slide potentiometers (faders), dynamic analog input noise filtering (EMA), and native **Bluetooth Low Energy (BLE)** integration.

![Project Status](https://img.shields.io/badge/Status-Active-brightgreen)
![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
![Framework](https://img.shields.io/badge/Framework-Arduino%20%2F%20PlatformIO-orange)
![Protocol](https://img.shields.io/badge/Protocol-BLE%20MIDI%20%2F%20HID-purple)
![License](https://img.shields.io/badge/License-MIT-yellow)

---

## 🌟 Key Features

- **4 Independent Channels:** Control individual volume sliders for Master, Game, Discord, and Music (DAW/Windows).
- **BLE MIDI & HID Support:** Plug-and-play Bluetooth connectivity with Windows, macOS, and Linux without extra drivers.
- **Exponential Moving Average (EMA) Filtering:** Software-level noise reduction to eliminate ADC jitter on ESP32.
- **Low Latency:** Optimized non-blocking polling loop for real-time responsiveness (<10ms latency).
- **3D Printed Enclosure Support:** Includes CAD files for desktop housing.

---

## 🛠️ Hardware Requirements

| Component | Quantity | Connection |
| :--- | :--- | :--- |
| **ESP32 DevKit V1** | 1 | MicroUSB (Power) |
| **10k Slide Potentiometers (Faders)** | 4 | Pins: ADC1_CH0 (GPIO 36), ADC1_CH3 (GPIO 39), ADC1_CH6 (GPIO 34), ADC1_CH7 (GPIO 35) |
| **Breadboard & Wires** | 1 | Standard jumper cables |

---

## 📐 Wiring Diagram
<img width="2816" height="1536" alt="Gemini_Generated_Image_k3akk1k3akk1k3ak" src="https://github.com/user-attachments/assets/f4c082fc-fa8e-4c42-8041-43b78ace8260" />
