#ifndef MQTT_H
#define MQTT_H

#include <WiFi.h>
#include <Arduino.h>
#include <string>
#include <PubSubClient.h>

using namespace std;

void mqtt_setup();
void mqtt_send(const char *chars);
void mqtt_loop();
void callback(char *topic, byte *payload, unsigned int length);

extern string lisence_plate;

#endif