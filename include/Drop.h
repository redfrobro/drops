#include <TFT_eSPI.h>

#define MAX_RADIUS 50

#ifndef Drop_h
#define Drop_h
#include "Arduino.h"

class Drop
{
private:
    int _height;
    int _width;
    int maxRadius;
    int speed;

public:
    Drop();
    void SetWidthHeight(int width, int height);
    void nextFrame();
    int radius;
    int x;
    int y;
    int r;
    int g;
    int b;
};

#endif