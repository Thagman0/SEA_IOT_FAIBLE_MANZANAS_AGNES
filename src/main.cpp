// See https://docs.espressif.com/projects/arduino-esp32/en/latest/api/adc.html
// Example of using ADC on ESP32 with Arduino framework
#include <Arduino.h>
#include <driver/adc.h>

void setup() {
    Serial.begin(115200);
    // Configure ADC on GPIO 36 (ADC1_CH0)
    analogSetPinAttenuation(36, (adc_attenuation_t)ADC_ATTEN_DB_12);  // Set attenuation to 12dB (max ~3.1V)
    analogSetWidth(12);                                               // Set ADC resolution to 12 bits (0-4095)
    pinMode(2, OUTPUT);  // Set GPIO 2 as output for LED
    /* 
    pinMode(2, OUTPUT_0); // Output UpDown to apply resistor
    */
}

void loop() {
    //1.3.2.2
    //Comment the println when terminal screenshot is not needed in order to keep temporal precision   
    //Serial.println("[Binome 01 - MANZANAS & AGNES] Hello Arduino World!");


    /*
    // Read raw ADC value (0-4095)
    int value = analogRead(36);
    // Serial.println("Value: " + String(value));

    // Convert raw value to millivolts (150-3100mV with 11dB or 12dB attenuation with ESP32)
    float voltage = (float)value * (3100.0 - 150.0) / 4095.0 + 150.0;

    // Directly read voltage in millivolts
    float direct_voltage = analogReadMilliVolts(36);

    // Print calculated and direct millivolt values
    
    Serial.println("Millivolts: " + String(voltage));
    Serial.println("Direct Millivolts: " + String(direct_voltage));
    */
   
    
    /*
    delay(2000);  // Wait 2 second
    */
    
    //1.4.2.1
    /*
    digitalWrite(2, HIGH);
    delay(50);  // N * 50 ms = 1 * 50 ms
    digitalWrite(2, LOW);
    delay(1950);  
    */

    //1.4.2.2
    // In this case on morse unit would be 50 ms as described by 50 * N ms = 50 * 1 ms = 50 ms
    //But this timing is to fast so we will mutliply it by 10 to be readable
    // SOS = ... --- ...
    int Morse_Unit = 500;
    // S = 3 dots = 3 * 50 ms = 150 ms 
    for (int i = 0; i < 3; i++) {
        digitalWrite(2, HIGH);
        delay(Morse_Unit);  // N * 50 ms = 1 * 50 ms
        digitalWrite(2, LOW);
        if (i < 2)  // Avoid delay after the last dot
            delay(Morse_Unit);
    }
    delay (3* Morse_Unit);  // Inter-letter space (3 units)
    // O = 3 dashes = 3 * 150 ms = 450 ms
    for (int i = 0; i < 3; i++) {
        digitalWrite(2, HIGH);
        delay(3 * Morse_Unit);  // N * 50 ms = 3 * 50 ms
        digitalWrite(2, LOW);
        if (i < 2)  // Avoid delay after the last dash
            delay(Morse_Unit);
    }
    delay (3 * Morse_Unit);  // Inter-letter space (3 units)
    // S = 3 dots = 3 * 50 ms = 150 ms
    for (int i = 0; i < 3; i++) {
        digitalWrite(2, HIGH);
        delay(Morse_Unit);  // N * 50 ms = 1 * 50 ms
        digitalWrite(2, LOW);
        if (i < 2)  // Avoid delay after the last dot
            delay(Morse_Unit);
    }
    delay (7 * Morse_Unit);  // Inter-Word space (7 units)
}