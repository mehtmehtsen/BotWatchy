#ifndef BOTWATCHY_H
#define BOTWATCHY_H

#include <Watchy.h>
#include "../include/images.h"
#include "../include/Calamity_Bold18pt7b.h"
#include "../include/Calamity_Bold8pt7b.h"
#include "../include/secrets.h"

typedef struct weatherDataOneCall{
  boolean invalid;
  int8_t temperature;
  int16_t weatherConditionCode0;
  int16_t weatherConditionCode1;
  int16_t weatherConditionCode2;
}weatherDataOneCall;

class BotWatchy : public Watchy
{
public:
  BotWatchy();
  void drawWatchFace();
  void drawTime();
  void drawDate();
  void drawWeather();
  void drawWeatherIcon(int8_t iconPosX, int16_t iconWeatherConditionCode);
  void drawBattery();
  void drawWifi();

  weatherDataOneCall getWeatherData();
};

#endif