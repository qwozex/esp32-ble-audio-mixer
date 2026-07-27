#include <Arduino.h>
#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32.h>
#include "config.h"

BLEMIDI_CREATE_INSTANCE(DEVICE_NAME, MIDI)

// Filtering state
float smoothedValues[NUM_FADERS] = {0};
int lastMidiValues[NUM_FADERS] = {-1};

// Exponential Moving Average Filter
float applyFilter(float currentVal, float previousSmoothed) {
    return (FILTER_ALPHA * currentVal) + ((1.0f - FILTER_ALPHA) * previousSmoothed);
}

void setup() {
    Serial.begin(115200);

    // Initialize ADC Pins
    for (int i = 0; i < NUM_FADERS; i++) {
        pinMode(FADER_PINS[i], INPUT);
        smoothedValues[i] = analogRead(FADER_PINS[i]);
    }

    // Initialize BLE MIDI
    MIDI.begin(MIDI_CHANNEL_OMNI);
    Serial.println("BLE MIDI Mixer initialized. Ready for pairing...");
}

void loop() {
    for (int i = 0; i < NUM_FADERS; i++) {
        int rawADC = analogRead(FADER_PINS[i]);

        // Smooth raw analog values to prevent jitter
        smoothedValues[i] = applyFilter((float)rawADC, smoothedValues[i]);

        // Map 12-bit ADC (0-4095) to 7-bit MIDI CC (0-127)
        int currentMidiVal = map((int)smoothedValues[i], 0, 4095, 0, 127);
        currentMidiVal = constrain(currentMidiVal, 0, 127);

        // Send MIDI Control Change message only if value significantly changes
        if (abs(currentMidiVal - lastMidiValues[i]) > 0) {
            MIDI.sendControlChange(i + 1, currentMidiVal, 1); // CC index: 1-4, Channel 1
            lastMidiValues[i] = currentMidiVal;

            Serial.print("Fader ");
            Serial.print(i + 1);
            Serial.print(" -> MIDI Value: ");
            Serial.println(currentMidiVal);
        }
    }

    delay(10); // Low-latency sampling interval
}