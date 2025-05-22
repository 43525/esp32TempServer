#include "WiFi.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#include <Wire.h>

#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_WIDTH 128 // OLED display width, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void oledDisplayHttp()
{
  display.clearDisplay();
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  // display IP address
  display.setCursor(0, 10);
  display.print(WIFI_SSID);
  display.setCursor(0, 25);
  display.print(WiFi.localIP());
  // display repository link
  display.setCursor(0, 40);
  display.print("github.com/43525/\n esp32TempServer");
  display.display();
}

void oledDisplayTemp(float t, float h)
{
  display.clearDisplay();
  display.setTextColor(WHITE);

  // display temperature
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print(t);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");

  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(h);
  display.print(" %");

  display.display();
}