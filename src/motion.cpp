#include "motion.h"
#include <Arduino.h>
#include "state-machine.h"

bool movement = false;

void move_callback()
{
    movement = true;
}

void motion_setup(int motionPin)
{
    pinMode(motionPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(motionPin), move_callback, FALLING);
}

void motion_loop()
{
    if (movement)
    {
        movement = false;
        transition(CAR_ARRIVED);
    }
}