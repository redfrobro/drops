#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "pin_config.h"
#include "Drop.h"

TFT_eSPI tft = TFT_eSPI();
std::array<Drop, NUMBERS_OF_CIRCLES> drops = {};
uint16_t color;


void setup() {
  pinMode(PIN_POWER_ON, OUTPUT);
  digitalWrite(PIN_POWER_ON, HIGH);
  
  tft.begin();
  tft.fillScreen(TFT_BLACK);

  tft.setRotation(3);
  randomSeed(analogRead(0));
  // initilize the drops
  for(Drop& drop : drops) {
    drop.SetWidthHeight(tft.width(), tft.height());
  }
  
}

void loop() {

  for(Drop& drop : drops) {
    drop.nextFrame();
    color = tft.color565(drop.r, drop.g, drop.b);
    tft.drawCircle(drop.x, drop.y, drop.radius, color);
  }
  
  delay(40);
  // erase the circles before the next loop
  for(Drop& drop : drops) {
    tft.drawCircle(drop.x, drop.y, drop.radius, TFT_BLACK);
  }
  
}