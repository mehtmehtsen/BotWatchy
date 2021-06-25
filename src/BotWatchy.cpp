#include "BotWatchy.h"
 
const int posHeart0X       = 10;
const int posHeart0Y       = 10;
const int posHeart1X       = 40;
const int posHeart1Y       = 10;
const int posHeart2X       = 70;
const int posHeart2Y       = 10;
const int posTemperatureX  = 144;
const int posTemperatureY  = 93;
const int posTriforceX     = 9;
const int posTriforceY     = 162;
const int posWeatherBaseX  = 44;
const int posWeatherBaseY  = 190;
const int posWeather0X     = 59;
const int posWeather0Y     = 157;
const int posWeather1X     = 101;
const int posWeather1Y     = 157;
const int posWeather2X     = 144;
const int posWeather2Y     = 157;
const int posWifiX         = 144;
const int posWifiY         = 37;

const float VOLTAGE_MIN = 3.2;
const float VOLTAGE_MAX = 4.1;
const float VOLTAGE_RANGE = 0.9;

BotWatchy::BotWatchy() {
    Serial.begin(115200);
    Serial.println("constructor");
}

void BotWatchy::drawWatchFace()
{
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);

  drawBattery();
  
  // display.drawBitmap(50, 50, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  // drawTime();
  // drawDate();
  // drawWeather();
  // display.drawBitmap(120, 77, WIFI_CONFIGURED ? wifi : wifioff, 26, 18, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
  // if(BLE_CONFIGURED){
  //     display.drawBitmap(100, 75, bluetooth, 13, 21, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
  // }
}

void BotWatchy::drawTime()
{
  // display.setFont(&DSEG7_Classic_Bold_53);
  // display.setCursor(5, 53+5);
  // if(currentTime.Hour < 10){
  //     display.print("0");
  // }
  // display.print(currentTime.Hour);
  // display.print(":");
  // if(currentTime.Minute < 10){
  //     display.print("0");
  // }
  // display.println(currentTime.Minute);
}

void BotWatchy::drawDate()
{
  // display.setFont(&Seven_Segment10pt7b);

  // int16_t  x1, y1;
  // uint16_t w, h;

  // String dayOfWeek = dayStr(currentTime.Wday);
  // display.getTextBounds(dayOfWeek, 5, 85, &x1, &y1, &w, &h);
  // display.setCursor(85 - w, 85);
  // display.println(dayOfWeek);

  // String month = monthShortStr(currentTime.Month);
  // display.getTextBounds(month, 60, 110, &x1, &y1, &w, &h);
  // display.setCursor(85 - w, 110);
  // display.println(month);

  // display.setFont(&DSEG7_Classic_Bold_25);
  // display.setCursor(5, 120);
  // if(currentTime.Day < 10){
  // display.print("0");
  // }
  // display.println(currentTime.Day);
  // display.setCursor(5, 150);
  // display.println(currentTime.Year + YEAR_OFFSET);// offset from 1970, since year is stored in uint8_t
}

void BotWatchy::drawBattery()
{
  float VBAT = getBatteryVoltage();
  // 12 battery states
  int batState = int(((VBAT - VOLTAGE_MIN) / VOLTAGE_RANGE) * 12);
  if (batState > 12) batState = 12;
  if (batState < 0) batState = 0;

  // display.setCursor(10, 50);
  // display.print(batState);
  
  if (batState == 12) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
  } else if (batState == 11) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_threequarters, 27, 22, GxEPD_BLACK);
  } else if (batState == 10) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_half, 27, 22, GxEPD_BLACK);
  } else if (batState == 9) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_quarter, 27, 22, GxEPD_BLACK);
  } else if (batState == 8) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  } else if (batState == 7) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_threequarters, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  } else if (batState == 6) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_half, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  } else if (batState == 5) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_quarter, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  } else if (batState == 4) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_full, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  } else if (batState == 3) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_threequarters, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  } else if (batState == 2) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_half, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  } else if (batState == 1) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_quarter, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  } else if (batState == 0) {
    display.drawBitmap(posHeart0X, posHeart0Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart1X, posHeart1Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
    display.drawBitmap(posHeart2X, posHeart2Y, epd_bitmap_heart_empty, 27, 22, GxEPD_BLACK);
  }

  // display.drawBitmap(154, 73, battery, 37, 21, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
  // display.fillRect(159, 78, 27, BATTERY_SEGMENT_HEIGHT, DARKMODE ? GxEPD_BLACK : GxEPD_WHITE);//clear battery segments
  // int8_t batteryLevel = 0;
  // float VBAT = getBatteryVoltage();
  // if(VBAT > 4.1){
  //     batteryLevel = 3;
  // }
  // else if(VBAT > 3.95 && VBAT <= 4.1){
  //     batteryLevel = 2;
  // }
  // else if(VBAT > 3.80 && VBAT <= 3.95){
  //     batteryLevel = 1;
  // }
  // else if(VBAT <= 3.80){
  //     batteryLevel = 0;
  // }

  // for(int8_t batterySegments = 0; batterySegments < batteryLevel; batterySegments++){
  //     display.fillRect(159 + (batterySegments * BATTERY_SEGMENT_SPACING), 78, BATTERY_SEGMENT_WIDTH, BATTERY_SEGMENT_HEIGHT, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
  // }
}

void BotWatchy::drawWeather()
{

  // weatherData currentWeather = getWeatherData();

  // int8_t temperature = currentWeather.temperature;
  // int16_t weatherConditionCode = currentWeather.weatherConditionCode;

  // display.setFont(&DSEG7_Classic_Regular_39);
  // int16_t  x1, y1;
  // uint16_t w, h;
  // display.getTextBounds(String(temperature), 100, 150, &x1, &y1, &w, &h);
  // display.setCursor(155 - w, 150);
  // display.println(temperature);
  // display.drawBitmap(165, 110, strcmp(TEMP_UNIT, "metric") == 0 ? celsius : fahrenheit, 26, 20, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
  // const unsigned char* weatherIcon;

  // //https://openweathermap.org/weather-conditions
  // if(weatherConditionCode > 801){//Cloudy
  // weatherIcon = cloudy;
  // }else if(weatherConditionCode == 801){//Few Clouds
  // weatherIcon = cloudsun;
  // }else if(weatherConditionCode == 800){//Clear
  // weatherIcon = sunny;
  // }else if(weatherConditionCode >=700){//Atmosphere
  // weatherIcon = cloudy;
  // }else if(weatherConditionCode >=600){//Snow
  // weatherIcon = snow;
  // }else if(weatherConditionCode >=500){//Rain
  // weatherIcon = rain;
  // }else if(weatherConditionCode >=300){//Drizzle
  // weatherIcon = rain;
  // }else if(weatherConditionCode >=200){//Thunderstorm
  // weatherIcon = rain;
  // }else
  // return;
  // display.drawBitmap(145, 158, weatherIcon, WEATHER_ICON_WIDTH, WEATHER_ICON_HEIGHT, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
}