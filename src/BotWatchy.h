#ifndef BOTWATCHY_H
#define BOTWATCHY_H

#include <Watchy.h>
#include "../include/images.h"

class BotWatchy : public Watchy{
    public:
        BotWatchy();
        void drawWatchFace();
        void drawTime();
        void drawDate();
        void drawWeather();
        void drawBattery();
};

#endif