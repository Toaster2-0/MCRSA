#include "led.h"
#include <Arduino.h>

int greenPin;
int redPin;
void led_setup(int greenLedPin, int redLedPin)
{
    greenPin = greenLedPin;
    pinMode(greenLedPin, OUTPUT);
    redPin = redLedPin;
    pinMode(redLedPin, OUTPUT);

    green_on();
}

void green_on()
{
    digitalWrite(greenPin, HIGH);
}
void green_off()
{
    digitalWrite(greenPin, LOW);
}
void red_on()
{
    digitalWrite(redPin, HIGH);
}
void red_off()
{
    digitalWrite(redPin, LOW);
}