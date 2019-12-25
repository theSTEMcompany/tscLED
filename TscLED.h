/*
  tscLED.cpp - A library for controlling LEDs
  Created by The Stem Company, Aug 9, 2019
*/

#ifndef TscLED_h
#define TscLED_h

#include "Arduino.h"
#include "TscPin.h"

class TscLED : public TscPin {
  public:
    TscLED(int pinNumber);
    void on();
    void off();
    void blink();
    void refresh();
    void setIntervalMillis(unsigned long intervalMillis);
    void startBlinking();
    void stopBlinking();

  private:
    unsigned long lastBlinkMillis = 0;
    unsigned long intervalMillis = 1000;
    int blinkModeActive;

};

#endif