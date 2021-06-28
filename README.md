# BotWatchy

This is a watch face for the open E-Ink display smartwatch [Watchy](https://watchy.sqfmi.com/).  
It is inspired by the HUD of 'The Legend of Zelda - Breath of the Wild' (BotW). The name is derived from the game's title and has nothing to do with any kind of bot. Rather, it's short for 'Breath of the Watchy'.

The idea was to apply the in-game HUD to RL, as it turned out BotW's HUD elements make an excellent way of displaying the data Watchy can provide.

## Features

- Display battery state as hearts (with support for quarter hearts, just as in-game).
- Display week day and date. Even though there is nothing comparable in BotW's HUD, I need this data displayed.
- Display time (duh) just like in-game, but bigger and betterer (for readability).
- Display if Watchy wearer's life runs in Master Mode by showing a Triforce in the lower left corner. As my life does so by default, that thing is just drawn no matter what.
- Display the weather as icons in a weather bar thingy, just like in-game (with the exception of an added icon for 'partly cloudy', as the game's icons were a bit vague on that for my taste). All weather data (including the one for the upcoming days) is requested from [openweathermap.org's one call API](https://openweathermap.org/api/one-call-api).  
If there's no WiFi to get weather data from, the Watch Face will just keep on displaying the data it got the last time.
  - Current weather is shown as the first icon.
  - Tomorrow's weather is shown as the second icon.
  - Day after tomorrow's weather is shown as the third icon.
- Display temperature in a temperature indicator just as in-game. Temperature is always displayed in Degrees Celcius. I'll leave implementing Fahrenheit to you, if you're into freaky stuff like that.  
Displayed temperature range is constrained between -12°C and 32°C.  
'Cold' zone begins at 0°C, 'hot' zone at 20°C. If your Watchy shows that the temperature is in those zones, make sure to switch into the right gear or boost your temperature resistance by consuming the appropriate food or medicine.  
With no WiFi, the temperature gotten from the last API call is displayed until there's a connection again. Default was to show the RTC temperature sensor's data, which only made sense for me if it's about 30°C outside.
- Display WiFi connectivity state using the Sheika sensor symbol. There's just 'on' or 'off'.

## Upload instructions

### I did not use Arduino IDE

I implemented BotWatchy using the [platformIO](https://platformio.org/) extension for VS Code, as I can't bear coding in the Arduino IDE anymore. I'm reasonably certain you can just clone this repo and open the project in any platformIO enabled IDE. All necessary dependencies should be installed automatically.  
I even added a `min_spiffs.csv` file and referenced it in the `platformio.ini`, which I think assures the compiler there's enough space on the ESP32 for all those bitmaps and stuff.  
What I want to say is: it's entirely possible platformIO will just compile and upload the code to your Watchy (but see right below first!).

### Your API key and location data

The Watchy library's authors apparently are way nicer people than I am, so they left their openweathermap.org API key in the code. I'm not that nice, so you'll have to use your own. Additionally, I don't want everybody to know my location, so what I did was I put my API key and location data into a file called `include/secrets.h`, included it in `src/BotWatchy.h` aaand... also added it to the `.gitignore`.  
I added a `include/secrets_template.h`, though, which you may copy as `include/secrets.h` and add your information to.

## Thanks and contributions

### Zelda BOTW UI Kit by Hunter Paramore

Although I added some stuff on my own, I heavily relied on this amazing Zelda BotW UI Kit done in Figma. I was really happy I didn't have to create all the graphics I used from scratch. So thanks to some internet person apparently named 'Hunter Paramore'. Here's a link to their [Figma profile](https://www.figma.com/@hparamore).

### Calamity Sans

For the UI font, I was able to use 'Calamity Sans' by reddit user [75thTrombone](https://www.reddit.com/user/75thTrombone/). I'd love to credit them in some way, but all I know of is this [reddit post](https://www.reddit.com/r/zelda/comments/5txuba/breath_of_the_wild_ui_font/).