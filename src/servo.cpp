#include <servo.h>

Servo servo;

void servo_setup(int servoPin)
{
    pinMode(servoPin, OUTPUT);
    servo.attach(servoPin);
    close();
}

void open()
{
    servo.write(0);
}
void close()
{
    servo.write(90);
}
