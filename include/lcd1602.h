#ifndef LCD1602_H
#define LCD1602_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <string>

using namespace std;

void lcd_setup(int sda_pin, int scl_pin);
void clear();
void setCursor(int x, int y);
void print(string message);
void displayDefaultMessage();

#endif