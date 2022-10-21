#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "pin_config.h"
#include "Drop.h"

#define NUMBERS_OF_CIRCLES 10

TFT_eSPI tft = TFT_eSPI();
Drop *drops[NUMBERS_OF_CIRCLES];
uint16_t color;


void setup() {
  pinMode(PIN_POWER_ON, OUTPUT);
  digitalWrite(PIN_POWER_ON, HIGH);
  
  tft.begin();
  tft.fillScreen(TFT_BLACK);

  tft.setRotation(3);
  randomSeed(analogRead(0));

  for (int i = 0; i < NUMBERS_OF_CIRCLES; ++i) {
    drops[i] = new Drop(tft.width(), tft.height());
  }
  
}

void loop() {

  for (int i = 0; i < NUMBERS_OF_CIRCLES; ++i) {
    drops[i]->nextFrame();
    color = tft.color565(drops[i]->r, drops[i]->g, drops[i]->b);
    tft.drawCircle(drops[i]->x, drops[i]->y, drops[i]->radius, color);
  }
  
  delay(30);

  for (int i = 0; i < NUMBERS_OF_CIRCLES; ++i) {
    tft.drawCircle(drops[i]->x, drops[i]->y, drops[i]->radius, TFT_BLACK);
  }
  
}