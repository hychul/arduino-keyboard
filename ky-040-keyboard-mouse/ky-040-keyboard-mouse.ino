#include <Keyboard.h>
#include <Mouse.h>

#define ROTARTY_PIN_CLK 2 // Connected pin number to CLK on KY-040
#define ROTARTY_PIN_DT 3 // Connected pin numbder to DT on KY-040
#define ROTARTY_PIN_SW 4 // Connected pin numbder to SW on KY-040
#define ROTARTY_BTN_RATE_MS 100 // Mininum button recognition milli second

/*
 * Syntax
 * Mouse.move(xVal, yVal, wheel)
 * 
 * Parameters
 * xVal: amount to move along the x-axis. Allowed data types: signed char.
 * yVal: amount to move along the y-axis. Allowed data types: signed char.
 * wheel: amount to move scroll wheel. Allowed data types: signed char.
 */

void setup() {
  setupRotary();
  setupRotaryButton();
}

void loop() {
  updateRotary();
  updateRotaryButton();
}

int lastRotaryVal;
boolean isClockwise;
int encoderPosCount = 0;

int lastRotaryButtonVal;
unsigned long lastRotaryButtonMs = 0;

void setupRotary() {
  pinMode(ROTARTY_PIN_CLK,INPUT);
  pinMode(ROTARTY_PIN_DT,INPUT);
  
  lastRotaryVal = digitalRead(ROTARTY_PIN_CLK);
  
  Mouse.begin();
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
    Mouse.move(100, 0, 0);
  } else {
    Serial.println("counterclockwise");
    Mouse.move(-100, 0, 0);
  }
  
  Serial.print("Encoder Position: ");
  Serial.println(encoderPosCount);
  
  lastRotaryVal = val;
}

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
