/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <hychome@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */

#define ROTARTY_PIN_CLK 2 // Connected pin number to CLK on KY-040
#define ROTARTY_PIN_DT 3 // Connected pin numbder to DT on KY-040
#define ROTARTY_PIN_SW 4 // Connected pin numbder to SW on KY-040
#define ROTARTY_BTN_RATE_MS 100 // Mininum rotary button recognition milli second

int lastRotaryVal;
boolean isClockwise;
int encoderPosCount = 0;

/*
 * +----------------------+
 * |        Rotary        |
 * +----------------------+
 */

void setupRotary() {
  pinMode(ROTARTY_PIN_CLK,INPUT);
  pinMode(ROTARTY_PIN_DT,INPUT);
  
  lastRotaryVal = digitalRead(ROTARTY_PIN_CLK);
}

void updateRotary() {
  int val = digitalRead(ROTARTY_PIN_CLK);

  if (val == lastRotaryVal) {
    return;
  }
  
  if (digitalRead(ROTARTY_PIN_DT) != val) {
    isClockwise = true;
    encoderPosCount ++;
  } else {
    isClockwise = false;
    encoderPosCount--;
  }
  
  Serial.print("Rotated: ");
  if (isClockwise) {
    Serial.println("clockwise");
  } else {
    Serial.println("counterclockwise");
  }
  
  Serial.print("Encoder Position: ");
  Serial.println(encoderPosCount);
  
  lastRotaryVal = val;
}

/*
 * +----------------------+
 * |     Rotary Button    |
 * +----------------------+
 */

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
  } else {
    Serial.println("released");
  }

  lastRotaryButtonVal = val;
  lastRotaryButtonMs = millis();
}
