# Duino-Coin-ESP-OLED

**Duino-Coin-ESP-OLED** is an custom ESP-based Duino-Coin miner with SSD1306 OLED support. This project utilizes an ESP8266 / ESP32 microcontroller to mine Duino-Coin and displays the mining status on an SSD1306 OLED display.
By default, it displays the Rig ID, hashrate, difficulty, shares and the connected node, but it can display other info too.

## Hardware wiring

Connect the SSD1306 OLED display to the ESP microcontroller as follows:

### ESP32

|SSD1306 Pin|ESP32 Pin|
|-----------|---------|
|VCC        |3.3V     |
|GND        |GND      |
|SCL        |GPIO22   |
|SDA        |GPIO21   |

### ESP8266

|SSD1306 Pin|ESP8266 Pin|
|-----------|-----------|
|VCC        |3.3V       |
|GND        |GND        |
|SCL        |GPIO5      |
|SDA        |GPIO4      |

## Configuration

Edit the `Settings.h` file and change the settings.
Edit the `Display.h` file to change the display.

## Donate

If you like Duino-Coin-ESP-OLED, consider making a donation. Every bit of support is greatly appreciated!

**Duino-Coin wallet**: `SladkyCitron`

Thank you for your support! 😊
