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

#define WIN_LAYER 0
#define MAC_LAYER 1
#define FN_LAYER 2

int rows[] = {ROW_0, ROW_1, ROW_2, ROW_3, ROW_4};
int columns[] = {COL_0, COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8, COL_9, COL_10, COL_11, COL_12, COL_13, COL_14};

struct Key {
  unsigned char ch;
  unsigned char action;

  bool isDown() {
    return ch != '\0' || action != 0;
  }

  bool isAction() {
    return action != 0;
  }

  unsigned char getCh() {
    if (action != 0) {
      return '!';
    }
    return ch;
  }

  void init() {
    ch = '\0';
    action = 0;
  }
};

Key keys[3][5][15] = {
  {
    {{KEY_ESC, 0}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0}, {'5', 0}, {'6', 0}, {'7', 0}, {'8', 0}, {'9', 0}, {'0', 0}, {'-', 0}, {'=', 0}, {KEY_BACKSPACE, 0}, {'\0', 0}},
    {{KEY_TAB, 0}, {'q', 0}, {'w', 0}, {'e', 0}, {'r', 0}, {'t', 0}, {'y', 0}, {'u', 0}, {'i', 0}, {'o', 0}, {'p', 0}, {'[', 0}, {']', 0}, {'\\', 0}, {KEY_DELETE, 0}},
    {{KEY_CAPS_LOCK, 0}, {'a', 0}, {'s', 0}, {'d', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {';', 0}, {'\'', 0}, {'\0', 0}, {KEY_RETURN, 0}, {'\0', 0}},
    {{KEY_LEFT_SHIFT, 0}, {'z', 0}, {'x', 0}, {'c', 0}, {'v', 0}, {'b', 0}, {'n', 0}, {'m', 0}, {',', 0}, {'.', 0}, {'/', 0}, {'\0', 0}, {KEY_RIGHT_SHIFT, 0}, {'\0', 0}, {KEY_UP_ARROW, 0}},
    {{KEY_LEFT_CTRL, 0}, {KEY_LEFT_GUI, 0}, {KEY_LEFT_ALT, 0}, {'\0', 0}, {'\0', 0}, {' ', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {KEY_RIGHT_ALT, 0}, {KEY_RIGHT_CTRL, 0}, {'^', 0}, {KEY_LEFT_ARROW, 0}, {KEY_DOWN_ARROW, 0}, {KEY_RIGHT_ARROW, 0}},
  },
  {
    {{KEY_ESC, 0}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0}, {'5', 0}, {'6', 0}, {'7', 0}, {'8', 0}, {'9', 0}, {'0', 0}, {'-', 0}, {'=', 0}, {KEY_BACKSPACE, 0}, {'\0', 0}},
    {{KEY_TAB, 0}, {'q', 0}, {'w', 0}, {'e', 0}, {'r', 0}, {'t', 0}, {'y', 0}, {'u', 0}, {'i', 0}, {'o', 0}, {'p', 0}, {'[', 0}, {']', 0}, {'\\', 0}, {KEY_DELETE, 0}},
    {{KEY_CAPS_LOCK, 0}, {'a', 0}, {'s', 0}, {'d', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {';', 0}, {'\'', 0}, {'\0', 0}, {KEY_RETURN, 0}, {'\0', 0}},
    {{KEY_LEFT_SHIFT, 0}, {'z', 0}, {'x', 0}, {'c', 0}, {'v', 0}, {'b', 0}, {'n', 0}, {'m', 0}, {',', 0}, {'.', 0}, {'/', 0}, {'\0', 0}, {KEY_RIGHT_SHIFT, 0}, {'\0', 0}, {KEY_UP_ARROW, 0}},
    {{KEY_LEFT_CTRL, 0}, {KEY_LEFT_GUI, 0}, {KEY_LEFT_ALT, 0}, {'\0', 0}, {'\0', 0}, {' ', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {KEY_RIGHT_ALT, 0}, {KEY_RIGHT_CTRL, 0}, {'^', 0}, {KEY_LEFT_ARROW, 0}, {KEY_DOWN_ARROW, 0}, {KEY_RIGHT_ARROW, 0}},
  },
  {
    {{'`', 0}, {KEY_F1, 0}, {KEY_F2, 0}, {KEY_F3, 0}, {KEY_F4, 0}, {KEY_F5, 0}, {KEY_F6, 0}, {KEY_F7, 0}, {KEY_F8, 0}, {KEY_F9, 0}, {KEY_F10, 0}, {KEY_F11, 0}, {KEY_F12, 0}, {KEY_BACKSPACE, 0}, {'\0', 0}},
    {{'\0', 0}, {'\0', 0}, {'\0', 1}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {KEY_INSERT, 0}},
    {{'\0', 0}, {'\0', 2}, {'\0', 3}, {'\0', 4}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {KEY_RETURN, 0}, {'\0', 0}},
    {{'\0', 0}, {'\0', 5}, {'\0', 0}, {'\0', 6}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {KEY_RIGHT_SHIFT, 0}, {'\0', 0}, {KEY_PAGE_UP, 0}},
    {{'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {KEY_RIGHT_ALT, 0}, {KEY_RIGHT_CTRL, 0}, {'^', 0}, {KEY_HOME, 0}, {KEY_PAGE_DOWN, 0}, {KEY_END, 0}},
  }
};

void (*actions[2][6])() = {
  {mouseMoveUp, mouseMoveDown, mouseMoveLeft, mouseMoveRight, mouseLeftPress, mouseRightPress},
  {mouseMoveDown, mouseMoveUp, mouseMoveRight, mouseMoveLeft, mouseLeftRelease, mouseRightRelease}
};

Key tildeKey = {'~', 0};

Key downKeys[5][15] = {
  {{'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}},
  {{'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}},
  {{'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}},
  {{'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}},
  {{'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}}
};

int keyLayer;

void setupKeyboard() {
  keyLayer = WIN_LAYER;

  for (char x =0; x < 5; x++) {
    pinMode(rows[x], INPUT_PULLUP);
  }

  for (char x = 0; x < 15; x++) {
    pinMode(columns[x], OUTPUT);
    digitalWrite(columns[x], HIGH);
  }
  
  Keyboard.begin();
}

void updateKeyboard() {
  for (char c = 0; c < 15; c++) {
    digitalWrite(columns[c], LOW);
    
    for (char r = 0; r < 5; r++) {
      bool isPressed = !digitalRead(rows[r]);

      updateKey(r, c, isPressed);
    }
    
    digitalWrite(columns[c], HIGH);
  }
}

void updateKey(char r, char c, bool isPressed) {
  bool isChanged = isPressed != downKeys[r][c].isDown();

  if (!isChanged) {
    return;
  }

  if (isPressed) {
    pressKey(r, c);
  } else {
    releaseKey(r, c);
  }
}

struct Key getKey(char r, char c) {
    if (r == 0 && c == 0 && isRightShiftDown()) {
      return tildeKey;
    }

    if (isFnDown()) {
      char ch = keys[FN_LAYER][r][c].getCh();
      return ch != '\0' ? keys[FN_LAYER][r][c] : keys[keyLayer][r][c];
    }
    
    return keys[keyLayer][r][c];
}

bool isRightShiftDown() {
  return downKeys[3][12].isDown();
}

bool isFnDown() {
  return downKeys[4][11].isDown();
}

void pressKey(char r, char c) {
    Key key = getKey(r, c);
    unsigned char ch = key.getCh();
    
    downKeys[r][c] = key;
    
    if (key.isAction()) {
      (*actions[0][key.action - 1])();
      return;
    } else if (ch == '\0' || ch == '^') {
      return;
    } else {
      Keyboard.press(ch);
    }
}

void releaseKey(char r, char c) {
    Key key = downKeys[r][c];
    unsigned char ch = key.getCh();
    
    downKeys[r][c].init();
    
    if (key.isAction()) {
      (*actions[1][key.action - 1])();
    } else if (ch == '\0' || ch == '^') {
      return;
    }  else {
      Keyboard.release(ch);
    }
}
