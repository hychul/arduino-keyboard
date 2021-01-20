/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <hychome@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */

void setupMouse() {
  Mouse.begin();
}

void updateMouse() {
  if (mouseX == 0 && mouseY == 0) {
    return;
  }

  Mouse.move(mouseX, mouseY);
}
