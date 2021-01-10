/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <hychome@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
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
