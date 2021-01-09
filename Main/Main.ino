/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <hychome@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */

// TODO: Check pin numbers
void setup() {
  setupKeyboard();
  setupMouse();
  setupRotary();
  setupRotaryButton();
  setupOled();
}

void loop() {
  updateKeyboard();
  updateMouse();
  updateRotary();
  updateRotaryButton();
  updateOled();
}
