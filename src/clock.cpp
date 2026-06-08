#include "clock.h"

void drawClock(Adafruit_SSD1306 &display) {

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.setCursor(20,25);
  display.println("12:34");

  display.display();
}