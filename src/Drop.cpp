#include <TFT_eSPI.h>
#include "Drop.h"
#include "Arduino.h"
#include "pin_config.h"

Drop::Drop(int width, int height)
{
    _height = height;
    _width = width;
    radius = random(MAX_RADIUS);
    maxRadius = MAX_RADIUS + random(-20, 20);
    if (RANDOM_SPEED)
    {
        speed = random(1, 5);
    }
    else
    {
        speed = 2;
    }
    r = random(255);
    g = random(255);
    b = random(255);
    x = random(20, _width - 20);
    y = random(20, _height - 20);
};

void Drop::nextFrame()
{
    if (radius < maxRadius)
    {
        if (SPEED_UP)
        {
            radius = radius + (int)((float)speed + (float)radius * 0.05);
        }
        else
        {
            radius = radius + speed;
        }
    }
    else
    {
        radius = 0;
        maxRadius = MAX_RADIUS + random(-20, 20);
        x = random(20, _width - 20);
        y = random(20, _height - 20);
        r = random(255);
        g = random(255);
        b = random(255);
    }
}