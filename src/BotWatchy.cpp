#include "BotWatchy.h"

const int posHeart0X = 10;
const int posHeart0Y = 10;
const int posHeart1X = 40;
const int posHeart1Y = 10;
const int posHeart2X = 70;
const int posHeart2Y = 10;
const int posTemperatureX = 144;
const int posTemperatureY = 93;
const int posTriforceX = 9;
const int posTriforceY = 162;
const int posWeatherBaseX = 44;
const int posWeatherBaseY = 150;
const int posWeather0X = 59;
const int posWeather0Y = 157;
const int posWeather1X = 101;
const int posWeather1Y = 157;
const int posWeather2X = 144;
const int posWeather2Y = 157;
const int posWifiX = 144;
const int posWifiY = 37;

const float VOLTAGE_MIN = 3.2;
const float VOLTAGE_MAX = 4.1;
const float VOLTAGE_RANGE = 0.9;

BotWatchy::BotWatchy()
{
  Serial.begin(115200);
  Serial.println("constructor");
}

void BotWatchy::drawWatchFace()
{
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);

  display.drawBitmap(posTriforceX, posTriforceY, epd_bitmap_triforce, 33, 28, GxEPD_BLACK);

  drawTime();
  drawDate();
  drawWeather();
  drawBattery();
  drawWifi();
}

void BotWatchy::drawTime()
{
}

void BotWatchy::drawDate()
{
}

void BotWatchy::drawBattery()
{
  float VBAT = getBatteryVoltage();

  // 12 battery states
  int batState = int(((VBAT - VOLTAGE_MIN) / VOLTAGE_RANGE) * 12);
  if (batState > 12)
    batState = 12;
  if (batState < 0)
    batState = 0;

  // display.setCursor(10, 50);
  // display.print(batState);

  if (batState == 12)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
  }
  else if (batState == 11)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_threequarters, 27, 22, GxEPD_BLACK);
  }
  else if (batState == 10)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_half, 27, 22, GxEPD_BLACK);
  }
  else if (batState == 9)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_quarter, 27, 22, GxEPD_BLACK);
  }
  else if (batState == 8)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  }
  else if (batState == 7)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_threequarters, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  }
  else if (batState == 6)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_half, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  }
  else if (batState == 5)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_quarter, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  }
  else if (batState == 4)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  }
  else if (batState == 3)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_threequarters, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  }
  else if (batState == 2)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_half, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  }
  else if (batState == 1)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_quarter, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  }
  else if (batState == 0)
  {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  }
}

void BotWatchy::drawWeather()
{
  display.drawBitmap(posWeatherBaseX, posWeatherBaseY, epd_bitmap_weather_base, 150, 40, GxEPD_BLACK);
  display.drawBitmap(posTemperatureX, posTemperatureY, epd_bitmap_temperature_base, 50, 50, GxEPD_BLACK);
}

void BotWatchy::drawWifi()
{
  display.drawBitmap(posWifiX, posWifiY, epd_bitmap_wifi_off, 50, 50, GxEPD_BLACK);
}