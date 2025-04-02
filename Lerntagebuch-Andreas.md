# 19.3.25

MCR Projekt erstellt.

# 24.3.25

MCR Projekt erste componenten (auch [mqtt](https://registry.platformio.org/libraries/knolleary/PubSubClient/examples/mqtt_esp8266/mqtt_esp8266.ino)) integrieren. -> externe servo und lcd libs wollen nicht so ganz. => mir wurden die falschen libs zum installieren gesagt
Enviroment variablen anlegen. -> .env scheint bei PlatformIO unüblich, variablen kommen vermutlich in platform.ini, muss noch getestst werden, erstmal nur runterschreiben.

# 25.3.25

MCR Projekt weitermachen vom Vortag.

# 26.3.25

MCR WIFI und [enviroment variables](https://community.platformio.org/t/pass-env-variables-at-build-time/4622). Löten des LCDs

# 31.3.25

MCR Verkabelung LCD und Servo. MQTT vollendet und getestet. Servo vollendet und getestet. [Motion Sensor](https://www.electronicwings.com/esp32/pir-sensor-interfacing-with-esp32). LCD zeigt nichts an...

# 2.4.25

MCR LCD vollendet. -> Doofer LCD musste noch eine schraube gedreht werden 😠. PIR Sensor ist zu grob (4 meter ist zu viel). => IR Sensor vollendet und getestet. LED integriert. BTN integriert. Technik bis auf UART fertig (get und set Parkplätze fehlt noch).
MCR UART jetzt auch fertig. MQTT Schnittstellen doku geschrieben.
