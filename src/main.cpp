#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "pin_config.h"
#include "Drop.h"

TFT_eSPI tft = TFT_eSPI();
Drop *drops[NUMBERS_OF_CIRCLES];
uint16_t color;
uint16_t fadeColor;


void setup() {
  pinMode(PIN_POWER_ON, OUTPUT);
  digitalWrite(PIN_POWER_ON, HIGH);
  
  tft.begin();
  tft.fillScreen(TFT_BLACK);

  tft.setRotation(3);
  randomSeed(analogRead(0));
  // initilize the drops
  for (int i = 0; i < NUMBERS_OF_CIRCLES; ++i) {
    drops[i] = new Drop(tft.width(), tft.height());
  }
  
}

void loop() {

  for (int i = 0; i < NUMBERS_OF_CIRCLES; ++i) {
    drops[i]->nextFrame();
    color = tft.color565(drops[i]->r, drops[i]->g, drops[i]->b);
    fadeColor = tft.color565(drops[i]->r / 2, drops[i]->g / 2, drops[i]->b / 2);
    tft.drawCircle(drops[i]->x, drops[i]->y, drops[i]->radius, color);
    if (FADE) {
      tft.drawCircle(drops[i]->x, drops[i]->y, drops[i]->radius - drops[i]->getSpeed(), fadeColor);
      tft.drawCircle(drops[i]->x, drops[i]->y, drops[i]->radius - drops[i]->getSpeed() * 2, fadeColor);
    }
  }
  
  delay(40);
  // erase the circles before the next loop
  for (int i = 0; i < NUMBERS_OF_CIRCLES; ++i) {
    tft.drawCircle(drops[i]->x, drops[i]->y, drops[i]->radius, TFT_BLACK);
    if (FADE) {
      tft.drawCircle(drops[i]->x, drops[i]->y, drops[i]->radius - drops[i]->getSpeed(), TFT_BLACK);
      tft.drawCircle(drops[i]->x, drops[i]->y, drops[i]->radius - drops[i]->getSpeed() * 2, TFT_BLACK);

    }
  }
  
}