#include "Button.hpp"

Button::Button(uint8_t pin, uint32_t debounceTime, bool pullUpEnabled,
               bool isInverted)
    : _pin(pin),
      _debounceTime(debounceTime),
      _pullUpEnabled(pullUpEnabled),
      _isInverted(isInverted),
      _state{0, false},
      _lastState{0, false} {
}

Button::~Button(void) {
}

void Button::begin(void) {
    pinMode(this->_pin, this->_pullUpEnabled ? INPUT_PULLUP : INPUT);
    this->_state = getState();
    this->_lastState = this->_state;
}

void Button::update(void) {
    const State state = getState();
    if (state.time - this->_state.time >= this->_debounceTime &&
        state.state != this->_state.state) {
        this->_lastState = this->_state;
        this->_state = state;
    } else {
        this->_state.time = state.time;
    }
    Serial.printf("Update: Last: %lu State = %d  Current: %lu State = %d",
                  this->_lastState.time, this->_lastState.state,
                  this->_state.time, this->_state.state);
    Serial.println();
}

bool Button::isPressed(void) const {
    return this->_state.state;
}

bool Button::isReleased(void) const {
    return !this->_state.state;
}

bool Button::wasPressed(void) const {
    return (this->_lastState.state != this->_state.state) && this->_state.state;
}

bool Button::wasReleased(void) const {
    return (this->_lastState.state != this->_state.state) &&
           !this->_state.state;
}

bool Button::pressedFor(uint32_t ms) const {
    return (this->_state.time - this->_lastState.time >= ms) &&
           this->_state.state;
}

bool Button::releasedFor(uint32_t ms) const {
    return (this->_state.time - this->_lastState.time >= ms) &&
           !this->_state.state;
}

const Button::State Button::getState(void) const {
    State state = {millis(), digitalRead(this->_pin)};
    if (this->_isInverted) {
        state.state = !state.state;
    }
    return state;
}
