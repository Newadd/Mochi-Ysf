#include "eyes.h"

void drawIdle(Adafruit_SSD1306 &display) {

  display.clearDisplay();

  display.fillCircle(40,32,14,WHITE);
  display.fillCircle(88,32,14,WHITE);

  display.fillCircle(40,32,5,BLACK);
  display.fillCircle(88,32,5,BLACK);

  display.display();
}

void drawHappy(Adafruit_SSD1306 &display) {

  display.clearDisplay();

  display.drawLine(25,30,55,38,WHITE);
  display.drawLine(73,38,103,30,WHITE);

  display.display();
}

void drawSleep(Adafruit_SSD1306 &display) {

  display.clearDisplay();

  display.drawLine(25,32,55,32,WHITE);
  display.drawLine(73,32,103,32,WHITE);

  display.display();
}

void drawHacker(Adafruit_SSD1306 &display) {

  display.clearDisplay();

  display.drawRect(20,20,40,20,WHITE);
  display.drawRect(68,20,40,20,WHITE);

  display.fillRect(30,28,20,4,WHITE);
  display.fillRect(78,28,20,4,WHITE);

  display.display();
}

void drawAnime(Adafruit_SSD1306 &display) {

  display.clearDisplay();

  display.fillCircle(40,32,18,WHITE);
  display.fillCircle(88,32,18,WHITE);

  display.fillCircle(40,32,8,BLACK);
  display.fillCircle(88,32,8,BLACK);

  display.fillCircle(36,26,2,WHITE);
  display.fillCircle(84,26,2,WHITE);

  display.display();
}