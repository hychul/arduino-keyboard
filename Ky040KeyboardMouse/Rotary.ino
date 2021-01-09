#define ROTARTY_PIN_CLK 2 // Connected pin number to CLK on KY-040
#define ROTARTY_PIN_DT 3 // Connected pin numbder to DT on KY-040

int lastRotaryVal;
boolean isClockwise;
int encoderPosCount = 0;

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
