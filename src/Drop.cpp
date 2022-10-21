#include <TFT_eSPI.h>
#include "Drop.h"
#include "Arduino.h" 

Drop::Drop(int width, int height) {
    _height = height;
    _width = width;
    radius = random(MAX_RADIUS);
    r = random(255);
    g = random(255);
    b = random(255);
    x = random(20, _width - 20);
    y = random(20, _height - 20);
    
};

void Drop::nextFrame() {
    if (radius < MAX_RADIUS) {
        radius = radius + 2;
    }
    else {
        radius = 0;
        x = random(20, _width - 20);
        y = random(20, _height - 20);
        r = random(255);
        g = random(255);
        b = random(255);
    }
}