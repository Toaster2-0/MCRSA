#include <Arduino.h>
#include "lcd1602.h"
#include "servo.h"
#include <WiFi.h>
#include "stdin.h"
#include <state-machine.h>
#include "mqtt.h"
#include "rtc.h"
#include "motion.h"
#include "btn.h"
#include "led.h"

#define GATE_TIMEOUT 10000

unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];

void setup()
{
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  lcd_setup(21, 22);
  servo_setup(13);
  motion_setup(34);
  btn_setup(32);
  led_setup(25, 26);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }
  mqtt_setup();
  rtc_setup();

  Serial.println("\nConnected to the WiFi network on IP");
}

void loop()
{

  static unsigned long time = 0;
  if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.reconnect();
    delay(100);
  }
  handle_stdin();
  motion_loop();
  mqtt_loop();
  btn_loop();

  switch (state)
  {
  case GATE_CLOSED:
  case WAITING_FOR_AUTH:
    if (millis() - time > 1000)
    {
      print(get_time().c_str());
      time = millis();
    }
    break;
  case GATE_OPENED:
    if (GATE_TIMEOUT < millis() - opened_at)
      transition(TIME_OVER);
    break;
  }
}
