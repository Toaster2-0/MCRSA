# setup

platformio.ini.example nach platformio.ini kopieren und variablen anpassen.

# MQTT Schnittstellen

Topics sind relativ zum MQTT_TOPIC setting.

## Topic out

Hier sendet der Microcontroller die Nachricht "WAITING_FOR_AUTH" wenn ein Auto angekommen ist.
Bei Veränderung der Parkplatzsituation sendet er "free_spaces" und die Anzahl der freien Parkplätze direkt im anschluss zu "free_spaces".

## Topic in

Hier hört der Microcontroller. Im Anschluss zu "WAITING_FOR_AUTH" sende "CAR_FORBIDDEN" wenn das Auto erlaubt ist, alles andere wird als Kennzeichen interpretiert.
