/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <hychome@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */

#include <Keyboard.h>

#define ROW_0 A2
#define ROW_1 A3
#define ROW_2 A4
#define ROW_3 A5
#define ROW_4 14

#define COL_0 11
#define COL_1 2
#define COL_2 3
#define COL_3 4
#define COL_4 5
#define COL_5 6
#define COL_6 7
#define COL_7 8
#define COL_8 9 
#define COL_9 10
#define COL_10 12
#define COL_11 15
#define COL_12 A0
#define COL_13 13
#define COL_14 A1

int rows[] = {ROW_0, ROW_1, ROW_2, ROW_3, ROW_4};
int columns[] = {COL_0, COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8, COL_9, COL_10, COL_11, COL_12, COL_13, COL_14};

unsigned char keys[5][15] = {
  {KEY_ESC, '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '=', '0', KEY_BACKSPACE, '\0'},
  {KEY_TAB, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\', KEY_DELETE},
  {KEY_CAPS_LOCK, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '\0', KEY_RETURN, '\0'},
  {KEY_LEFT_SHIFT, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '\0', KEY_RIGHT_SHIFT, '\0', KEY_UP_ARROW},
  {KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_LEFT_ALT, '\0', '\0', ' ', '\0', '\0', '\0',  KEY_RIGHT_ALT, KEY_RIGHT_CTRL, '^', KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}
};

unsigned char fnKeys[5][15] = {
  {'`', KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F11, KEY_F12, KEY_F10, KEY_BACKSPACE, '\0'},
  {KEY_TAB, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\', KEY_DELETE},
  {KEY_CAPS_LOCK, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '\0', KEY_RETURN, '\0'},
  {KEY_LEFT_SHIFT, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '\0', KEY_RIGHT_SHIFT, '\0', KEY_UP_ARROW},
  {KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_LEFT_ALT, '\0', '\0', ' ', '\0', '\0', '\0',  KEY_RIGHT_ALT, KEY_RIGHT_CTRL, '^', KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}
};

char keyDowns[5][15] = {
  {'\0',}, {'\0',}, {'\0',}, {'\0',}, {'\0',}
};

void setup() {
  setupKeyboard();
}

void loop() {
  readKeyboard();
}

void setupKeyboard() {
  for (char x =0; x < 5; x++) {
    pinMode(rows[x], INPUT_PULLUP);
  }

  for (char x = 0; x < 15; x++) {
    pinMode(columns[x], OUTPUT);
    digitalWrite(columns[x], HIGH);
  }
  
  Keyboard.begin();
}

void readKeyboard() {
  for (char c = 0; c < 15; c++) {
    digitalWrite(columns[c], LOW);
    
    for (char r = 0; r < 5; r++) {
      bool isPressed = !digitalRead(rows[r]);

      readKey(r, c, isPressed);
    }
    
    digitalWrite(columns[c], HIGH);
  }
}

void readKey(char r, char c, bool isPressed) {
  unsigned char ch = updateKeyDown(r, c, isPressed);
  
  if (ch == '\0' || ch == '^') {
    return;
  }
  
  if (isPressed) {
    Keyboard.press(ch);
  } else if (!isKeyDown(r, c)) {
    Keyboard.release(ch);
  }
}

bool isKeyDown(char r, char c) {
  return keyDowns[r][c] != '\0';
}

bool isFnDown() {
  return isKeyDown(4, 11);
}

bool isRightShiftDown() {
  return isKeyDown(3, 12);
}

char updateKeyDown(char r, char c, bool isPressed) {
  if (isPressed == isKeyDown(r, c)) {
    return keyDowns[r][c];
  }

  if (isPressed) {
    if (r == 0 && c == 0 && isRightShiftDown()) {
      keyDowns[r][c] = '~';
    } else {
      keyDowns[r][c] = isFnDown() ? fnKeys[r][c] : keys[r][c];
    }
  } else {
    keyDowns[r][c] = '\0';
  }
  
  return keyDowns[r][c];
}
