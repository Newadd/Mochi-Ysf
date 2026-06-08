#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "config.h"
#include "state.h"
#include "eyes.h"
#include "touch.h"
#include "clock.h"

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    -1
);

EyeMode currentMode = MODE_IDLE;

unsigned long lastInteraction = 0;

void renderMode() {

  switch(currentMode) {

    case MODE_IDLE:
      drawIdle(display);
      break;

    case MODE_HAPPY:
      drawHappy(display);
      break;

    case MODE_SLEEP:
      drawSleep(display);
      break;

    case MODE_HACKER:
      drawHacker(display);
      break;

    case MODE_ANIME:
      drawAnime(display);
      break;

    case MODE_CLOCK:
      drawClock(display);
      break;
  }
}

void nextMode() {

  currentMode =
      (EyeMode)((currentMode + 1) % 5);

  renderMode();
}

void setup() {

  pinMode(TOUCH_PIN, INPUT);

  Wire.begin(
      OLED_SDA,
      OLED_SCL
  );

  display.begin(
      SSD1306_SWITCHCAPVCC,
      OLED_ADDR
  );

  display.clearDisplay();

  renderMode();

  lastInteraction = millis();
}

void loop() {

  if (touchPressed()) {

    nextMode();

    lastInteraction = millis();

    display.invertDisplay(true);
    delay(50);
    display.invertDisplay(false);
  }

  if (millis() - lastInteraction > 30000) {

    currentMode = MODE_CLOCK;

    drawClock(display);
  }

  delay(20);
}