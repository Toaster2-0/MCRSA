#include "state-machine.h"
#include <Arduino.h>
#include <mqtt.h>
#include "servo.h"
#include "lcd1602.h"
#include "led.h"
#include <string>

const unsigned int maxSpaces = 3;
unsigned int freeSpaces = maxSpaces;
// globale Variable
State_t state = GATE_CLOSED;
long opened_at = 0;

void change_spaces(int changeBy)
{
    if (maxSpaces < freeSpaces + changeBy)
        return;
    freeSpaces += changeBy;
    string msg = "free_spaces";
    msg += to_string(freeSpaces);
    mqtt_send(msg.c_str());
    if (freeSpaces > 0)
    {
        green_on();
        red_off();
    }
    else
    {
        green_off();
        red_on();
    }
}

void set_state(State_t newState)
{
    state = newState;
    switch (newState)
    {
    case GATE_CLOSED:
        lisence_plate = "good bye";
        close();
        break;
    case WAITING_FOR_AUTH:
        mqtt_send("WAITING_FOR_AUTH");
        break;
    case GATE_OPENED:
        print(lisence_plate);
        open();
        opened_at = millis();
        break;
    }
}

void transition(Event_t event)
{
    switch (state)
    {
    case GATE_CLOSED:
        if (CAR_ARRIVED == event)
        {
            if (freeSpaces > 0)
            {
                set_state(WAITING_FOR_AUTH);
            }
        }
        else if (OPEN_GATE == event)
        {
            change_spaces(1);
            set_state(GATE_OPENED);
        }
        break;
    case WAITING_FOR_AUTH:
        if (CAR_ALLOWED == event)
        {
            change_spaces(-1);
            set_state(GATE_OPENED);
        }
        else if (CAR_DISALLOWED == event)
        {
            set_state(GATE_CLOSED);
        }
        break;
    case GATE_OPENED:
        if (TIME_OVER == event)
        {
            set_state(GATE_CLOSED);
        }
        break;
    default:
        break;
    }
}