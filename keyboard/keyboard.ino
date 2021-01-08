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
  {KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_LEFT_ALT, '\0', '\0', ' ', '\0', '\0', '\0',  KEY_RIGHT_ALT, KEY_RIGHT_CTRL, '\0', KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}
};

unsigned char fnKeys[5][15] = {
  {'`', KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F11, KEY_F12, KEY_F10, KEY_BACKSPACE, '\0'},
  {KEY_TAB, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\', KEY_DELETE},
  {KEY_CAPS_LOCK, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '\0', KEY_RETURN, '\0'},
  {KEY_LEFT_SHIFT, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '\0', KEY_RIGHT_SHIFT, '\0', KEY_UP_ARROW},
  {KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_LEFT_ALT, '\0', '\0', ' ', '\0', '\0', '\0',  KEY_RIGHT_ALT, KEY_RIGHT_CTRL, '\0', KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}
};

bool keyDowns[5][15] = {
  {false,}, {false,}, {false,}, {false,}, {false,}
};

bool isFnPressed = false; // r: 4, c: 11

void setup() {
  // put your setup code here, to run once:
  for (char x =0; x < 5; x++) {
    pinMode(rows[x], INPUT_PULLUP);
  }

  for (char x = 0; x < 15; x++) {
    pinMode(columns[x], OUTPUT);
    digitalWrite(columns[x], HIGH);
  }
  
  Keyboard.begin();
}

void loop() {
  for (char c = 0; c < 15; c++) {
    digitalWrite(columns[c], LOW);
    
    for (char r = 0; r < 5; r++) {
      bool isPressed = !digitalRead(rows[r]);
      
      if (r == ROW_4 && c == COL_11) {
        isFnPressed = isPressed;
      }
      
      unsigned char ch = isFnPressed ? fnKeys[r][c] : keys[r][c];
      
      if (ch == '\0') {
        continue;
      }
      
      if (isPressed) {
        Keyboard.press(ch);
        keyDowns[r][c] = true;
      } else if (keyDowns[r][c]) {
        Keyboard.release(keys[r][c]);
        Keyboard.release(fnKeys[r][c]);
        keyDowns[r][c] = false;
      }
    }
    
    digitalWrite(columns[c], HIGH);
  }
}
