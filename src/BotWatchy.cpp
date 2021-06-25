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
  display.setFont(&Calamity_Bold18pt7b);
  display.setCursor(12, 140);
  if (currentTime.Hour < 10)
    display.print("0");
  display.print(currentTime.Hour);
  display.print(":");
  if (currentTime.Minute < 10)
    display.print("0");
  display.println(currentTime.Minute);
}

void BotWatchy::drawDate()
{
  display.setFont(&Calamity_Bold8pt7b);

  String dayOfWeek = dayStr(currentTime.Wday);
  String month = monthStr(currentTime.Month);

  display.setCursor(12, 68);
  display.println(dayOfWeek);

  display.setCursor(12, 87);
  display.print(month);
  display.print(" ");

  display.print(currentTime.Day);
  if (currentTime.Day == 1)
    display.print("st");
  else if (currentTime.Day == 2)
    display.print("nd");
  else if (currentTime.Day == 3)
    display.print("rd");
  else
    display.print("th");
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
  weatherData currentWeather = getWeatherData();

  int8_t temperature = currentWeather.temperature;
  int16_t weatherConditionCode = currentWeather.weatherConditionCode;

  display.drawBitmap(posWeatherBaseX, posWeatherBaseY, epd_bitmap_weather_base, 150, 40, GxEPD_BLACK);
  display.drawBitmap(posTemperatureX, posTemperatureY, epd_bitmap_temperature_base, 50, 50, GxEPD_BLACK);

  //https://openweathermap.org/weather-conditions
  if (weatherConditionCode > 801) //Cloudy
    display.drawBitmap(posWeather0X, posWeather0Y, epd_bitmap_weather_clouds, 27, 27, GxEPD_WHITE);
  else if (weatherConditionCode == 801) //Few Clouds
    display.drawBitmap(posWeather0X, posWeather0Y, epd_bitmap_weather_clouds, 27, 27, GxEPD_WHITE);
  else if (weatherConditionCode == 800) //Clear
    display.drawBitmap(posWeather0X, posWeather0Y, epd_bitmap_weather_sun, 27, 27, GxEPD_WHITE);
  else if (weatherConditionCode >= 700) //Atmosphere
    display.drawBitmap(posWeather0X, posWeather0Y, epd_bitmap_weather_clouds, 27, 27, GxEPD_WHITE);
  else if (weatherConditionCode >= 600) //Snow
    display.drawBitmap(posWeather0X, posWeather0Y, epd_bitmap_weather_snow, 27, 27, GxEPD_WHITE);
  else if (weatherConditionCode >= 500) //Rain
    display.drawBitmap(posWeather0X, posWeather0Y, epd_bitmap_weather_rain, 27, 27, GxEPD_WHITE);
  else if (weatherConditionCode >= 300) //Drizzle
    display.drawBitmap(posWeather0X, posWeather0Y, epd_bitmap_weather_rain, 27, 27, GxEPD_WHITE);
  else if (weatherConditionCode >= 200) //Thunderstorm
    display.drawBitmap(posWeather0X, posWeather0Y, epd_bitmap_weather_flash, 27, 27, GxEPD_WHITE);
  else
    return;
  // display.drawBitmap(145, 158, weatherIcon, WEATHER_ICON_WIDTH, WEATHER_ICON_HEIGHT, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
}

void BotWatchy::drawWifi()
{
  display.drawBitmap(posWifiX, posWifiY, WIFI_CONFIGURED ? epd_bitmap_wifi_on : epd_bitmap_wifi_off, 50, 50, GxEPD_BLACK);
}