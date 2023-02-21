#include "M5AtomS3.hpp"

#if defined(TARGET_M5ATOMS3)
const char* M5AtomS3::NAME = "M5AtomS3";
#elif defined(TARGET_M5ATOMS3_LITE)
const char* M5AtomS3::NAME = "M5AtomS3 Lite";
#else
#warning "You should specify -DTARGET_M5ATOMS3 or -DTARGET_M5ATOMS3_LITE"
#endif

M5AtomS3 M5;

M5AtomS3::M5AtomS3(void) : Btn(BUTTON_PIN) {
}

M5AtomS3::~M5AtomS3(void) {
}

void M5AtomS3::begin(bool isSerialEnabled, bool isI2CEnabled) {
    if (isSerialEnabled) {
        Serial.begin(DEFAULT_SERIAL_BAUDRATE);
#ifdef STARTUP_SERIAL_DELAY_MS
        delay(STARTUP_SERIAL_DELAY_MS);
#endif
        Serial.printf("%s initializing...OK", NAME);
        Serial.println();
    }
    if (isI2CEnabled) {
        Wire.begin(SDA, SCL, DEFAULT_I2C_FREQUENCY);
    }
    Btn.begin();
}

void M5AtomS3::update(void) {
    Btn.update();
}
