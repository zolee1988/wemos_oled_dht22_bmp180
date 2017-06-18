#include <SPI.h>
#include <Wire.h>
#include <SFE_MicroOLED.h>
#include <DHT.h>
#include <Adafruit_BMP085.h>

#define PIN_RESET 255
#define DC_JUMPER 0
#define DHTPIN D4
#define DHTTYPE DHT22

MicroOLED oled(PIN_RESET, DC_JUMPER);
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 bmp;

void setup()   {
  oled.begin();
  oled.clear(ALL);
  oled.display();
  oled.clear(PAGE);
  oled.display();

  dht.begin();
  bmp.begin();
  
  }

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  oled.clear(PAGE);
  oled.setFontType(0);
  oled.setCursor(0,0);
  oled.print("DHT temp:");
  oled.setCursor(0,10);
  oled.setFontType(1);
  oled.print(t);
  oled.print("*C");

  oled.setFontType(0);
  oled.setCursor(0,25);
  oled.print("BMP temp:");
  oled.setCursor(0,35);
  oled.setFontType(1);
  oled.print(bmp.readTemperature());
  oled.print("*C");

  oled.display();
  delay(2000);

  oled.clear(PAGE);
  oled.setFontType(0);
  oled.setCursor(0,0);
  oled.print("DHT hum:");
  oled.setCursor(0,10);
  oled.setFontType(1);
  oled.print(h);
  oled.print("%");
  
  oled.display();
  delay(2000);
    
  }
