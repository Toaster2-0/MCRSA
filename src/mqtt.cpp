#include "mqtt.h"
#include "state-machine.h"

string lisence_plate = "good bye";

WiFiClient wifi;
PubSubClient client(wifi);

string to_string(byte *chars, unsigned int length)
{
    string str = "";
    for (int i = 0; i < length; i++)
    {
        str += (char)chars[i];
    }
    return str;
}

void mqtt_send(const char *msg)
{
    client.publish(MQTT_TOPIC "out", msg);
}

void reconnect()
{
    // Loop until we're reconnected
    for (int i = 0; i < 3 && !client.connected(); i++)
    {
        Serial.print("Attempting MQTT connection...");
        // Create a random client ID
        String clientId = "ESP8266Client-";
        clientId += String(random(0xffff), HEX);
        // Attempt to connect
        if (client.connect(clientId.c_str()))
        {
            Serial.println("connected");
            // Once connected, publish an announcement...
            // ... and resubscribe
            client.subscribe(MQTT_TOPIC "in");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

void callback(char *topic, byte *payload, unsigned int length)
{
    if (strcmp(topic, MQTT_TOPIC "in") == 0)
    {
        if (state == WAITING_FOR_AUTH)
        {
            string msg = to_string(payload, length);
            if (msg == "CAR_FORBIDDEN")
            {
                transition(CAR_DISALLOWED);
                if (DEBUG)
                {
                    Serial.println("Car forbidden");
                }
            }
            else
            {
                lisence_plate = msg;
                transition(CAR_ALLOWED);
                if (DEBUG)
                {
                    Serial.print("Car ");
                    Serial.print(lisence_plate.c_str());
                    Serial.println(" allowed");
                }
            }
        }
    }
}

void mqtt_setup()
{
    client.setServer(BROKER_URL, 1883);
    client.setCallback(callback);
}

void mqtt_loop()
{
    if (!client.connected())
        reconnect();
    client.loop();
}