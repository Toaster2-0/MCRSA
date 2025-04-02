#include "btn.h"
#include <Arduino.h>
#include "state-machine.h"

bool btnPressed = false;
long lastPressed = 0;
void on_btn_pressed()
{
    if (millis() - lastPressed > 100)
    {
        btnPressed = true;
        lastPressed = millis();
    }
}

void btn_setup(int btnPin)
{
    pinMode(btnPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(btnPin), on_btn_pressed, FALLING);
}

void btn_loop()
{
    if (btnPressed)
    {
        btnPressed = false;
        transition(OPEN_GATE);
    }
}