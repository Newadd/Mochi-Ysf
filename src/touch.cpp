#include <Arduino.h>
#include "config.h"

bool touchPressed() {

  static bool last = false;

  bool now = digitalRead(TOUCH_PIN);

  bool result = now && !last;

  last = now;

  return result;
}