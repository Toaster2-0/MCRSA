#include <servo.h>

Servo servo;

void servo_setup(int servoPin)
{
    pinMode(servoPin, OUTPUT);
    servo.attach(servoPin);
    servo.write(0);
}

void open()
{
    servo.write(90);
}
void close()
{
    servo.write(0);
}
