#include <Arduino.h>

// Import required libraries
#include "WiFi.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include "ESPAsyncWebServer.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>

// import from folder 'include'
#include "dhtWeb.h"
#include "oledDisplay.h"

// *** Update with your network credentials, WIFI_SSID, WIFI_PASS thru Gitbash
#define DHTPIN 15 // Digital pin connected to the DHT sensor

// boolean displayTemp = false;
const int buttonPin = 4; // the number of the pushbutton pin

// variable for storing the pushbutton status
int buttonState = 0;

void setup()
{
  // Serial port for debugging purposes
  Serial.begin(115200);
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  delay(2000);
  display.clearDisplay();

  beginServer();

  oledDisplayHttp();
  delay(5000); // Shown for 5 sec
}

void loop()
{
  // read the state of the pushbutton value
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW)
  {
    oledDisplayHttp();
    delay(5000); // Shown for 5 sec
  }

  // read temperature and humidilty
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
  }

  oledDisplayTemp(t, h);
}