

int lastRotaryButtonVal;
unsigned long lastRotaryButtonMs = 0;

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
    Keyboard.press(KEY_A);
  } else {
    Serial.println("released");
    Keyboard.release(KEY_A);
  }

  lastRotaryButtonVal = val;
  lastRotaryButtonMs = millis();
}
