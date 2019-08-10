/*
  CzMotor.cpp -
  Created by CZ, Feb 11, 2019
*/

#include "Arduino.h"
#include "CzMotor.h"

tscLED::tscLED(int ledPin)
{
  this->ledPin = ledPin;
}

void tscLED::on()
{
  digitalWrite(this->ledPin, HIGH);
}

void tscLED::off()
{
  digitalWrite(this->ledPin, LOW);
}

void tscLED::startBlinking()
{
  this->blinkModeActive = true;
  this->lastBlinkMillis = millis();
}

void tscLED::stopBlinking()
{
  this->blinkModeActive = false;
}

void tscLED::refresh()
{
  if (!this->blinkModeActive) {
    return;
  }

  if (millis() - this->lastBlinkMillis >= this->offIntervalMillis) {
    this->toggleLED();
    this->lastBlinkMillis = millis();
  }
}

void setOffIntervalMillis(int offIntervalMillis)
{
  this->offIntervalMillis = offIntervalMillis;
}

void setOnIntervalMillis(int onIntervalMillis)
{
  this->onIntervalMillis = onIntervalMillis;
}

void toggleLED()
{
  int ledStatus = digitalRead(this->ledPin);

  if (ledStatus) {
    this->on();
  } else {
    this->off();
  }
}


