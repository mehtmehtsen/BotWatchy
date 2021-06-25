#ifndef BOTWATCHY_H
#define BOTWATCHY_H

#include <Watchy.h>
#include "../include/images.h"
#include "../include/Calamity_Bold16pt7b.h"
#include "../include/Calamity_Bold36pt7b.h"

class BotWatchy : public Watchy
{
public:
  BotWatchy();
  void drawWatchFace();
  void drawTime();
  void drawDate();
  void drawWeather();
  void drawBattery();
  void drawWifi();
};

#endif