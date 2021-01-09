/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <hychome@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */
 
#include <Mouse.h>

signed char mouseX = 0;
signed char mouseY = 0;
signed char mouseSpeed = 3;

void setupMouse() {
  Mouse.begin();
}

void updateMouse() {
  if (mouseX == 0 && mouseY == 0) {
    return;
  }

  Mouse.move(mouseX, mouseX, 0);
}

void mouseMoveUp() {
  mouseY += mouseSpeed;
}

void mouseMoveDown() {
  mouseY -= mouseSpeed;
}

void mouseMoveLeft() {
  mouseX -= mouseSpeed;
}

void mouseMoveRight() {
  mouseX += mouseSpeed;
}

void mouseLeftPress() {
  Mouse.press(MOUSE_LEFT);
}

void mouseLeftRelease() {
  Mouse.release(MOUSE_LEFT);
}

void mouseRightPress() {
  Mouse.press(MOUSE_RIGHT);
}

void mouseRightRelease() {
  Mouse.release(MOUSE_RIGHT);
}
