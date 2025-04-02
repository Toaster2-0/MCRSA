#include "state-machine.h"
#include <Arduino.h>
#include "mqtt.h"
void handle_stdin()
{
    if (Serial.available() > 0)
    {
        static string newSpaces = "";
        int incomingByte = Serial.read();
        switch (incomingByte)
        {
        case 'h':
            Serial.println("h: hilfe\n"
                           "s: aktueller status\n"
                           "n: event auto angekommen\n"
                           "a: event auto erlaubt\n"
                           "d: event auto nicht erlaubt\n"
                           "t: event zeit um, schranke schließt\n"
                           "o: event öffne Schranke\n"
                           "f: anzahl freie Plätze anzeigen\n"
                           "[zahl]: neue Parkplätze eingeben und anschließend [enter]\n");
            break;
        case 's':
            Serial.print("Aktueller status: ");
            Serial.println(state);
            break;

        case 'n':
            transition(CAR_ARRIVED);
            break;

        case 'a':
            transition(CAR_ALLOWED);
            break;

        case 'd':
            transition(CAR_DISALLOWED);
            break;

        case 't':
            transition(TIME_OVER);
            break;
        case 'o':
            transition(OPEN_GATE);
            break;
        case 'f':
            Serial.print("Freie Parkplätze: ");
            Serial.println(freeSpaces);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            newSpaces += (char)incomingByte;
            Serial.print("neue Parkplätze: ");
            Serial.println(newSpaces.c_str());
            break;
        case '\r':
        case '\n':
            if (newSpaces != "")
            {
                freeSpaces = stoi(newSpaces);
                Serial.print(freeSpaces);
                Serial.println(" Parkplätze sind frei. ");
                newSpaces = "";
            }
            break;

        default:
            Serial.println("unbekannte eingabe");
            break;
        }
    }
}