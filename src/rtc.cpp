#include "rtc.h"
#include <Arduino.h>
#include <WiFiUdp.h>
#include <string>

WiFiUDP ntpUDP;

const long timeZoneOffset = 2 * 3600;
NTPClient timeClient(ntpUDP, timeZoneOffset);

void rtc_setup()
{

    for (int i = 0; i < 300 && !timeClient.update(); i++)
    {
        delay(100);
    }
    if (!timeClient.isTimeSet())
    {
        Serial.println("Error getting time");
    }
}

String get_time()
{
    return timeClient.getFormattedTime();
    // std::string timestring = std::to_string(timeClient.getHours()) + ":" + std::to_string(timeClient.getMinutes()) + ":" + std::to_string(timeClient.getSeconds());
    // const char *stri = timestring.c_str();
    // return stri;
}