#include "M5AtomS3.hpp"

void setup(void) {
    M5.begin();
}

void loop(void) {
    M5.update();
    if (M5.Btn.wasPressed()) {
        Serial.println("Pressed");
    }
    if (M5.Btn.wasReleased()) {
        Serial.println("Released");
    }
    if (M5.Btn.pressedFor(5000)) {
        Serial.println("Pressed for 5sec");
    }
    if (M5.Btn.releasedFor(5000)) {
        Serial.println("Released for 5sec");
    }
    delay(100);
}
