// Settings.h
#ifndef SETTINGS_H
#define SETTINGS_H

// ---------------------- General settings ---------------------- //
// Change the part in brackets to your Duino-Coin username
extern const char DUCO_USER[] = "my_cool_username";
// Change the part in brackets to your mining key (if you have set it in the wallet)
extern const char MINER_KEY[] = "mySecretPass";
// Change the part in brackets if you want to set a custom miner name
// Use Auto to autogenerate, None for no custom identifier
extern const char RIG_IDENTIFIER[] = "None";
// Change the part in brackets to your WiFi name
extern const char SSID[] = "SSID";
// Change the part in brackets to your WiFi password
extern const char PASSWORD[] = "PASSW0RD";

// Uncomment if you want to host the dashboard page (available on ESPs IP address)
// #define WEB_DASHBOARD

// Uncomment if you want to use LAN8720. WLAN-credentials will be ignored using LAN
// Select correct Board in ArduinoIDE!!! Really!
// #define USE_LAN

// Comment out the line below if you wish to disable LED blinking
#define LED_BLINKING

// Comment out the line below if you wish to disable Serial printing
#define SERIAL_PRINTING

// Comment out the lines below if you wish to disable SSD1306 OLED display
#define USE_SSD1306
// select the size of display, USE_DISPLAY_128x64 OR USE_DISPLAY_128x32
#define USE_DISPLAY_128x64
//#define USE_DISPLAY_128x32

// -------------------------------------------------------------- //

// ---------------------- IoT examples -------------------------- //
// https://github.com/revoxhere/duino-coin/wiki/Duino's-take-on-the-Internet-of-Things

// Uncomment the line below if you wish to use the internal temperature sensor (Duino IoT example)
// Only ESP32-S2, -S3, -H2, -C2, -C3, -C6 and some old models have one!
// More info: https://www.espboards.dev/blog/esp32-inbuilt-temperature-sensor/
// NOTE: Mining performance will decrease by about 20 kH/s!32
// #define USE_INTERNAL_SENSOR

// Uncomment the line below if you wish to use a DS18B20 temperature sensor (Duino IoT example)
// NOTE: Mining performance should stay the same
// #define USE_DS18B20

// Uncomment the line below if you wish to use a DHT11/22 temperature and humidity sensor (Duino IoT example)
// NOTE: Untested as of right now
// #define USE_DHT
// -------------------------------------------------------------- //

#if defined(ESP8266)
    // ESP8266
    #define LED_BUILTIN 2
#elif defined(CONFIG_FREERTOS_UNICORE) 
    // ESP32-S2
    #define LED_BUILTIN 15
#else
    // ESP32
    #define LED_BUILTIN 2
#endif

#define BLINK_SETUP_COMPLETE 2
#define BLINK_CLIENT_CONNECT 5

#define SOFTWARE_VERSION "4.0"
extern unsigned int hashrate = 0;
extern unsigned int difficulty = 0;
extern unsigned long share_count = 0;
extern String node_id = "";
extern String WALLET_ID = "";

#if defined(USE_SSD1306)
  // Install Adafruit_GFX and Adafruit_SSD1306 libraries if you get an error
  #include <Wire.h>
  #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1306.h>

  // Change this to your display's I2C address
  #define SCREEN_ADDRESS 0x3C

  // Change this to your display's reset pin (-1 = disabled)
  #define OLED_RESET -1

  #if defined(USE_DISPLAY_128x64)
    // Change this to your display's resolution    
    #define SCREEN_WIDTH 128
    #define SCREEN_HEIGHT 64
  #endif

  #if defined(USE_DISPLAY_128x32)
    // Change this to your display's resolution    
    #define SCREEN_WIDTH 128
    #define SCREEN_HEIGHT 32
  #endif

  Adafruit_SSD1306 extern display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#endif

#if defined(USE_INTERNAL_SENSOR)
  #include "driver/temp_sensor.h"
#endif

#if defined(USE_DS18B20)
  // Install OneWire and DallasTemperature libraries if you get an error
  #include <OneWire.h>
  #include <DallasTemperature.h>
  // Change 12 to the pin you've connected your sensor to
  #define DSPIN 12
  
  OneWire oneWire(DSPIN);
  DallasTemperature extern sensors(&oneWire);
#endif

#if defined(USE_DHT)
  // Install "DHT sensor library" if you get an error
  #include <DHT.h>
  // Change 12 to the pin you've connected your sensor to
  #define DHTPIN 12
  // Set DHT11 or DHT22 type accordingly
  #define DHTTYPE DHT11
  
  DHT extern dht(DHTPIN, DHTTYPE);
#endif

#endif  // End of SETTINGS_H
