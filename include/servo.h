#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include <ESP32Servo.h>

void servo_setup(int servoPin);
void open();
void close();

#endif