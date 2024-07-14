#ifndef DISPLAY_H
#define DISPLAY_H

#include <ArduinoJson.h>

#if defined(ESP8266)
    #include <ESP8266HTTPClient.h>
#else
    #include <WiFiClientSecure.h>
    #include <HTTPClient.h>
#endif

#include "Settings.h"

void updateDisplay() {
	display.clearDisplay();
	display.setCursor(0,0);
	display.setTextColor(SSD1306_WHITE);

	// Actual rendering here; Uncomment things and configure how you want
	//displayFish(1);
	displayRigID(2);
	displaySpace(1);
	displayHashrate(1);
	displayDifficulty(1);
	displayShareCount(1);
	displayNodeID(1);
	//displayRigID(1);
	//displayUsername(1);
	//displayUserBalance(1);
	//displayUserMinerCount(1);
	/////////////////////////

	display.display();
}

// Displays fish as requested by @KD BRUHLAG
void displayFish(int size = 1) {
	display.setTextSize(size);
	display.println("><> ><> ><> ><> ><> ><> ><> ><> ><> ><>");
}

// Displays space
void displaySpace(int size = 1) {
	display.setTextSize(size);
	display.println("");
}

// Displays username
void displayUsername(int size = 1) {
	display.setTextSize(size);
	#if defined(USE_DISPLAY_128x64)
		display.println("Username: " + String(DUCO_USER));
	#endif

	#if defined(USE_DISPLAY_128x32)
		display.println("User:" + String(DUCO_USER));
	#endif
}

// Displays hashrate
void displayHashrate(int size = 1) {
	display.setTextSize(size);
	#if defined(USE_DISPLAY_128x64)
		display.println("Hashrate: " + String(hashrate / 1000) + " kH/s");
	#endif

	#if defined(USE_DISPLAY_128x32)
		display.println("H/R:" + String(hashrate / 1000) + "kH/s");
	#endif
}

// Displays difficulty
void displayDifficulty(int size = 1) {
	display.setTextSize(size);
	#if defined(USE_DISPLAY_128x64)
		display.println("Difficulty: " + String(difficulty / 100));
	#endif

	#if defined(USE_DISPLAY_128x32)
		display.println("Diff:" + String(difficulty / 100));
	#endif
}

// Displays rig ID
void displayRigID(int size = 1) {
	display.setTextSize(size);
    display.setTextColor(SSD1306_WHITE);
    display.println(String(RIG_IDENTIFIER));
}

// Displays share count
void displayShareCount(int size = 1) {
	display.setTextSize(size);
	display.println("Shares: " + String(share_count));
}

// Displays node ID
void displayNodeID(int size = 1) {
	display.setTextSize(size);
	display.println("Node: " + String(node_id));
}

// Displays user balance
void displayUserBalance(int size = 1) {
	String input = httpGetString("https://server.duinocoin.com/balances/"+String(DUCO_USER));

    DynamicJsonDocument doc(1024);
    deserializeJson(doc, input);
    double balance = doc["result"]["balance"];

	display.setTextSize(size);
    #if defined(USE_DISPLAY_128x64)
		display.println("Balance: " + String(balance));
	#endif

	#if defined(USE_DISPLAY_128x32)
		display.println("Bal:" + String(balance));
	#endif
}

// Displays user miner count
void displayUserMinerCount(int size = 1) {
	String input = httpGetString("https://server.duinocoin.com/miners/"+String(DUCO_USER));

	DynamicJsonDocument doc(4096); // TODO: <= toto
    deserializeJson(doc, input);
	JsonArray result = doc["result"];
    size_t miners = result.size();

	display.setTextSize(size);
	display.println("Miners: " + String(miners));
}

// Helper function; fetches a HTTP string
String httpGetString(String URL) {
    String payload = "";
    WiFiClientSecure client;
    client.setInsecure();
    HTTPClient http;

    if (http.begin(client, URL)) {
    	int httpCode = http.GET();

    	if (httpCode == HTTP_CODE_OK) payload = http.getString();
    	else {
			#if defined(SERIAL_PRINTING)
        		Serial.printf("Error fetching HTTP string: %s\n", http.errorToString(httpCode).c_str());
        	#endif
		}

    	http.end();
    }
    return payload;
}

#endif