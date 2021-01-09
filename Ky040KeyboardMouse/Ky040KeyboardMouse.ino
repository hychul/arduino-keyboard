#include <Keyboard.h>
#include <Mouse.h>

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
