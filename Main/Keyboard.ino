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

#define KEY_NONE '\0'

#define KEY_1 1
#define KEY_2 2
#define KEY_3 3
#define KEY_4 4
#define KEY_5 5
#define KEY_6 6
#define KEY_7 7
#define KEY_8 8
#define KEY_9 9
#define KEY_0 0

#define KEY_A 'a'
#define KEY_B 'b'
#define KEY_C 'c'
#define KEY_D 'd'
#define KEY_E 'e'
#define KEY_F 'f'
#define KEY_G 'g'
#define KEY_H 'h'
#define KEY_I 'i'
#define KEY_J 'j'
#define KEY_K 'k'
#define KEY_L 'l'
#define KEY_M 'm'
#define KEY_N 'n'
#define KEY_O 'o'
#define KEY_P 'p'
#define KEY_Q 'q'
#define KEY_R 'r'
#define KEY_S 's'
#define KEY_T 't'
#define KEY_U 'u'
#define KEY_V 'v'
#define KEY_W 'w'
#define KEY_X 'x'
#define KEY_Y 'y'
#define KEY_Z 'z'

#define KEY_BACKTICK '`'
#define KEY_TILDE '~'
#define KEY_MINUS '-'
#define KEY_EQUALS '='
#define KEY_LEFT_BRAKET '['
#define KEY_RIGHT_BRAKET ']'
#define KEY_BACKSLASH '\\'
#define KEY_SEMICOLON ';'
#define KEY_QUOTE '\''
#define KEY_COMMA ','
#define KEY_PERIOD '.'
#define KEY_SLASH '/'
#define KEY_SPACE ' '

#define KEY_FUNCTION '^'
#define KEY_ACTION '!'

#define ACTION_NONE 99
#define ACTION_MOUSE_UP 0
#define ACTION_MOUSE_DOWN 1
#define ACTION_MOUSE_LEFT 2
#define ACTION_MOUSE_RIGHT 3
#define ACTION_MOUSE_LEFT_CLICK 4
#define ACTION_MOUSE_RIGHT_CLICK 5

int rows[] = {ROW_0, ROW_1, ROW_2, ROW_3, ROW_4};
int columns[] = {COL_0, COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8, COL_9, COL_10, COL_11, COL_12, COL_13, COL_14};

struct Key {
  unsigned char ch;
  unsigned char action;

  bool isDown() {
    return ch != KEY_NONE || action != ACTION_NONE;
  }

  unsigned char getCh() {
    if (action != ACTION_NONE) {
      return KEY_ACTION;
    }
    return ch;
  }

  void init() {
    ch = KEY_NONE;
    action = ACTION_NONE;
  }
};

Key keys[3][5][15] = {
  {
    {{KEY_ESC, ACTION_NONE}, {KEY_1, ACTION_NONE}, {KEY_2, ACTION_NONE}, {KEY_3, ACTION_NONE}, {KEY_4, ACTION_NONE}, {KEY_5, ACTION_NONE}, {KEY_6, ACTION_NONE}, {KEY_7, ACTION_NONE}, {KEY_8, ACTION_NONE}, {KEY_9, ACTION_NONE}, {KEY_0, ACTION_NONE}, {KEY_MINUS, ACTION_NONE}, {KEY_EQUALS, ACTION_NONE}, {KEY_BACKSPACE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}},
    {{KEY_TAB, ACTION_NONE}, {KEY_Q, ACTION_NONE}, {KEY_W, ACTION_NONE}, {KEY_E, ACTION_NONE}, {KEY_R, ACTION_NONE}, {KEY_T, ACTION_NONE}, {KEY_Y, ACTION_NONE}, {KEY_U, ACTION_NONE}, {KEY_I, ACTION_NONE}, {KEY_O, ACTION_NONE}, {KEY_P, ACTION_NONE}, {KEY_LEFT_BRAKET, ACTION_NONE}, {KEY_RIGHT_BRAKET, ACTION_NONE}, {KEY_BACKSLASH, ACTION_NONE}, {KEY_DELETE, ACTION_NONE}},
    {{KEY_CAPS_LOCK, ACTION_NONE}, {KEY_A, ACTION_NONE}, {KEY_S, ACTION_NONE}, {KEY_D, ACTION_NONE}, {KEY_F, ACTION_NONE}, {KEY_G, ACTION_NONE}, {KEY_H, ACTION_NONE}, {KEY_J, ACTION_NONE}, {KEY_K, ACTION_NONE}, {KEY_L, ACTION_NONE}, {KEY_SEMICOLON, ACTION_NONE}, {KEY_QUOTE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_RETURN, ACTION_NONE}, {KEY_NONE, ACTION_NONE}},
    {{KEY_LEFT_SHIFT, ACTION_NONE}, {KEY_Z, ACTION_NONE}, {KEY_X, ACTION_NONE}, {KEY_C, ACTION_NONE}, {KEY_V, ACTION_NONE}, {KEY_B, ACTION_NONE}, {KEY_N, ACTION_NONE}, {KEY_M, ACTION_NONE}, {KEY_COMMA, ACTION_NONE}, {KEY_PERIOD, ACTION_NONE}, {KEY_SLASH, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_RIGHT_SHIFT, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_UP_ARROW, ACTION_NONE}},
    {{KEY_LEFT_CTRL, ACTION_NONE}, {KEY_LEFT_GUI, ACTION_NONE}, {KEY_LEFT_ALT, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_SPACE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_RIGHT_ALT, ACTION_NONE}, {KEY_RIGHT_CTRL, ACTION_NONE}, {KEY_FUNCTION, ACTION_NONE}, {KEY_LEFT_ARROW, ACTION_NONE}, {KEY_DOWN_ARROW, ACTION_NONE}, {KEY_RIGHT_ARROW, ACTION_NONE}},
  },
  {
    {{KEY_ESC, ACTION_NONE}, {KEY_1, ACTION_NONE}, {KEY_2, ACTION_NONE}, {KEY_3, ACTION_NONE}, {KEY_4, ACTION_NONE}, {KEY_5, ACTION_NONE}, {KEY_6, ACTION_NONE}, {KEY_7, ACTION_NONE}, {KEY_8, ACTION_NONE}, {KEY_9, ACTION_NONE}, {KEY_0, ACTION_NONE}, {KEY_MINUS, ACTION_NONE}, {KEY_EQUALS, ACTION_NONE}, {KEY_BACKSPACE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}},
    {{KEY_TAB, ACTION_NONE}, {KEY_Q, ACTION_NONE}, {KEY_W, ACTION_NONE}, {KEY_E, ACTION_NONE}, {KEY_R, ACTION_NONE}, {KEY_T, ACTION_NONE}, {KEY_Y, ACTION_NONE}, {KEY_U, ACTION_NONE}, {KEY_I, ACTION_NONE}, {KEY_O, ACTION_NONE}, {KEY_P, ACTION_NONE}, {KEY_LEFT_BRAKET, ACTION_NONE}, {KEY_RIGHT_BRAKET, ACTION_NONE}, {KEY_BACKSLASH, ACTION_NONE}, {KEY_DELETE, ACTION_NONE}},
    {{KEY_CAPS_LOCK, ACTION_NONE}, {KEY_A, ACTION_NONE}, {KEY_S, ACTION_NONE}, {KEY_D, ACTION_NONE}, {KEY_F, ACTION_NONE}, {KEY_G, ACTION_NONE}, {KEY_H, ACTION_NONE}, {KEY_J, ACTION_NONE}, {KEY_K, ACTION_NONE}, {KEY_L, ACTION_NONE}, {KEY_SEMICOLON, ACTION_NONE}, {KEY_QUOTE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_RETURN, ACTION_NONE}, {KEY_NONE, ACTION_NONE}},
    {{KEY_LEFT_SHIFT, ACTION_NONE}, {KEY_Z, ACTION_NONE}, {KEY_X, ACTION_NONE}, {KEY_C, ACTION_NONE}, {KEY_V, ACTION_NONE}, {KEY_B, ACTION_NONE}, {KEY_N, ACTION_NONE}, {KEY_M, ACTION_NONE}, {KEY_COMMA, ACTION_NONE}, {KEY_PERIOD, ACTION_NONE}, {KEY_SLASH, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_RIGHT_SHIFT, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_UP_ARROW, ACTION_NONE}},
    {{KEY_LEFT_CTRL, ACTION_NONE}, {KEY_LEFT_GUI, ACTION_NONE}, {KEY_LEFT_ALT, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_SPACE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_RIGHT_ALT, ACTION_NONE}, {KEY_RIGHT_CTRL, ACTION_NONE}, {KEY_FUNCTION, ACTION_NONE}, {KEY_LEFT_ARROW, ACTION_NONE}, {KEY_DOWN_ARROW, ACTION_NONE}, {KEY_RIGHT_ARROW, ACTION_NONE}},
  },
  {
    {{KEY_BACKTICK, ACTION_NONE}, {KEY_F1, ACTION_NONE}, {KEY_F2, ACTION_NONE}, {KEY_F3, ACTION_NONE}, {KEY_F4, ACTION_NONE}, {KEY_F5, ACTION_NONE}, {KEY_F6, ACTION_NONE}, {KEY_F7, ACTION_NONE}, {KEY_F8, ACTION_NONE}, {KEY_F9, ACTION_NONE}, {KEY_F10, ACTION_NONE}, {KEY_F11, ACTION_NONE}, {KEY_F12, ACTION_NONE}, {KEY_BACKSPACE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}},
    {{KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_MOUSE_UP}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_INSERT, ACTION_NONE}},
    {{KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_MOUSE_LEFT}, {KEY_NONE, ACTION_MOUSE_DOWN}, {KEY_NONE, ACTION_MOUSE_RIGHT}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_RETURN, ACTION_NONE}, {KEY_NONE, ACTION_NONE}},
    {{KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_MOUSE_LEFT_CLICK}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_MOUSE_RIGHT_CLICK}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_RIGHT_SHIFT, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_PAGE_UP, ACTION_NONE}},
    {{KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_RIGHT_ALT, ACTION_NONE}, {KEY_RIGHT_CTRL, ACTION_NONE}, {KEY_FUNCTION, ACTION_NONE}, {KEY_HOME, ACTION_NONE}, {KEY_PAGE_DOWN, ACTION_NONE}, {KEY_END, ACTION_NONE}},
  }
};

void (*actions[2][6])() = {
  {mouseMoveUp, mouseMoveDown, mouseMoveLeft, mouseMoveRight, mouseLeftPress, mouseRightPress},
  {mouseMoveDown, mouseMoveUp, mouseMoveRight, mouseMoveLeft, mouseLeftRelease, mouseRightRelease}
};

Key tildeKey = {KEY_TILDE, ACTION_NONE};

Key downKeys[5][15] = {
  {{KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}},
  {{KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}},
  {{KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}},
  {{KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}},
  {{KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}, {KEY_NONE, ACTION_NONE}}
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

void pressKey(char r, char c) {
    Key key = getKey(r, c);
    unsigned char ch = key.getCh();
    
    downKeys[r][c] = key;
    
    if (ch == KEY_NONE || ch == KEY_FUNCTION) {
      return;
    } 
    
    if (ch == KEY_ACTION) {
      (*actions[0][key.action])();
    } else {
      Keyboard.press(ch);
    }
}

struct Key getKey(char r, char c) {
    if (r == 0 && c == 0 && isRightShiftDown()) {
      return tildeKey;
    }

    if (isFnDown()) {
      char ch = keys[FN_LAYER][r][c].getCh();
      return ch != KEY_NONE ? keys[FN_LAYER][r][c] : keys[keyLayer][r][c];
    }
    
    return keys[keyLayer][r][c];
}

bool isRightShiftDown() {
  return downKeys[3][12].isDown();
}

bool isFnDown() {
  return downKeys[4][11].isDown();
}

void releaseKey(char r, char c) {
    Key key = downKeys[r][c];
    unsigned char ch = key.getCh();
    
    downKeys[r][c].init();
    
    if (ch == KEY_NONE || ch == KEY_FUNCTION) {
      return;
    }

    if (ch == KEY_ACTION) {
      (*actions[1][key.action])();
    } else {
      Keyboard.release(ch);
    }
}
