/*
 * Syntax
 * Mouse.move(xVal, yVal, wheel)
 * 
 * Parameters
 * xVal: amount to move along the x-axis. Allowed data types: signed char.
 * yVal: amount to move along the y-axis. Allowed data types: signed char.
 * wheel: amount to move scroll wheel. Allowed data types: signed char.
 */
#define ROTARTY_PIN_CLK 23 // Connected pin number to CLK on KY-040
#define ROTARTY_PIN_DT 24 // Connected pin numbder to DT on KY-040
#define ROTARTY_PIN_SW 22 // Connected pin numbder to SW on KY-040
#define ROTARTY_BTN_RATE_MS 100 // Mininum button recognition milli second

void setup() {
  setupRotary();
  setupRotaryButton();
  
  Serial.begin(9600);
}

void loop() {
  updateRotary();
  updateRotaryButton();
}
