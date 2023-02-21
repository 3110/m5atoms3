#pragma once

#include <Arduino.h>
#include <Wire.h>

#include "Button.hpp"

class M5AtomS3 {
public:
    static const char* NAME;

    static const int SDA = GPIO_NUM_38;
    static const int SCL = GPIO_NUM_39;
    static const int BUTTON_PIN = GPIO_NUM_41;

    static const unsigned long DEFAULT_SERIAL_BAUDRATE = 115200UL;
    static const uint32_t DEFAULT_I2C_FREQUENCY = 100000UL;

    M5AtomS3(void);
    ~M5AtomS3(void);

    void begin(bool isSerialEnabled = true, bool isI2CEnabled = true);
    void update(void);

    Button Btn;
};

extern M5AtomS3 M5;
