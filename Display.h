#ifndef DISPLAY_H
#define DISPLAY_H

#include "Settings.h"

void updateDisplay() {
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println(String(RIG_IDENTIFIER));

    display.setTextSize(1);
    display.println();
    display.println("Hashrate: " + String(hashrate / 1000) + " kH/s");
    display.println("Difficulty: " + String(difficulty / 100));
    display.println("Shares: " + String(share_count));
    display.println("Node: " + String(node_id));

    display.display();
}

#endif