#define ROTARTY_PIN_SW 4 // Connected pin numbder to SW on KY-040
#define ROTARTY_BTN_RATE_MS 100 // Mininum button recognition milli second

int lastRotaryButtonVal;
unsigned long lastRotaryButtonMs = 0;

void setupRotaryButton() {
  pinMode(ROTARTY_PIN_SW,INPUT);
  
  lastRotaryButtonVal = digitalRead(ROTARTY_PIN_SW);

  Keyboard.begin();
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
    Keyboard.press('a');
  } else {
    Serial.println("released");
    Keyboard.release('a');
  }

  lastRotaryButtonVal = val;
  lastRotaryButtonMs = millis();
}
