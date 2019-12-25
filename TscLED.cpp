/*
  TscLED.cpp -
  Created by The STEM Company, Aug 9, 2019
*/

#include "Arduino.h"
#include "TscPin.h"
#include "TscLED.h"


TscLED::TscLED(int ledPin) : TscPin(ledPin, OUTPUT) {}

void TscLED::on()
{
    this->setHigh();
}

void TscLED::off()
{
    this->setLow();
}

void TscLED::startBlinking()
{
    this->blinkModeActive = true;
    this->lastBlinkMillis = millis();
}

void TscLED::stopBlinking()
{
  this->blinkModeActive = false;
}

void TscLED::refresh()
{
  if (!this->blinkModeActive) {
    return;
  }

  if (millis() - this->lastBlinkMillis >= this->intervalMillis) {
    this->toggleSignal();
    this->lastBlinkMillis = millis();
  }
}

void TscLED::setIntervalMillis(unsigned long intervalMillis)
{
  this->intervalMillis = intervalMillis;
}


