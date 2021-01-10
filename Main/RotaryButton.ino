/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <hychome@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */

void setupRotaryButton() {
  pinMode(ROTARTY_PIN_SW,INPUT);
  
  lastRotaryButtonVal = digitalRead(ROTARTY_PIN_SW);
}

void updateRotaryButton() {
  int val = digitalRead(ROTARTY_PIN_SW);

  if (val == lastRotaryButtonVal) {
    return;
  }

  if (millis() < lastRotaryButtonMs + ROTARTY_BTN_RATE_MS) {
    return;
  }

  Serial.print("Switch: ");
  if (val == LOW) {
    Serial.println("pushed");
  } else {
    Serial.println("released");
  }

  lastRotaryButtonVal = val;
  lastRotaryButtonMs = millis();
}
