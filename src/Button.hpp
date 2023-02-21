#pragma once

#include <Arduino.h>

class Button {
public:
    typedef struct
    {
        uint32_t time;
        bool state;
    } State;

    static const uint32_t DEBOUNCE_TIME_MS = 25;

    Button(uint8_t pin, uint32_t debounceTime = DEBOUNCE_TIME_MS,
           bool pullUpEnabled = true, bool isInverted = true);
    ~Button(void);

    void begin(void);
    void update(void);

    bool isPressed(void) const;
    bool isReleased(void) const;
    bool wasPressed(void) const;
    bool wasReleased(void) const;
    bool pressedFor(uint32_t ms) const;
    bool releasedFor(uint32_t ms) const;

protected:
    const State getState(void) const;

private:
    uint8_t _pin;
    uint32_t _debounceTime;
    bool _pullUpEnabled;
    bool _isInverted;

    State _state;
    State _lastState;
};