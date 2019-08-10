/*
  tscLED.cpp - A library for controlling LEDs
  Created by The Stem Company, Aug 9, 2019
*/

#ifndef tscLED_h
#define tscLED_h

#include "Arduino.h"

class tscLED {
  public:
    tscLED(int pinNumber)
    void on();
    void off();
    void blink();
    void refresh();
    void setOffIntervalMillis(int offIntervalMillis);
    void setOnIntervalMillis(int onIntervalMillis);

  private:
    int stepPin
    int lastBlinkMillis;
    int offIntervalMillis = 1000;
    int onIntervalMillis = 1000;
    int blinkModeActive;
    void toggleLED()

};

#endif