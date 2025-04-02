#include "lcd1602.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void lcd_setup(int sda_pin, int scl_pin)
{
    pinMode(sda_pin, OUTPUT);
    pinMode(scl_pin, OUTPUT);
    Wire.begin(sda_pin, scl_pin); // SDA = Pin 21, SCL = Pin 22 (ESP32 Standard)
    lcd.init();                   // Initialisiert das LCD
    lcd.backlight();              // Hintergrundbeleuchtung einschalten
    lcd.clear();                  // Display leeren
    lcd.setCursor(0, 0);
    lcd.print("Ready!");
    delay(1000); // 1 Sekunde anzeigen
    lcd.clear();
}

void clear()
{
    lcd.clear();
}

void setCursor(int x, int y)
{
    lcd.setCursor(x, y);
}

void print(string message)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message.c_str());
}
