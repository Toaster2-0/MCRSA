#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

typedef enum
{
  GATE_CLOSED,
  WAITING_FOR_AUTH,
  GATE_OPENED,
} State_t;

typedef enum
{
  CAR_ARRIVED,
  CAR_ALLOWED,
  CAR_DISALLOWED,
  TIME_OVER,
  OPEN_GATE
} Event_t;

extern State_t state;
extern long opened_at;
extern unsigned int freeSpaces;

void transition(Event_t event);

#endif