/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <hychome@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */

void setupKeyboard() {
  keyLayer = WIN_LAYER;

  for (int i = 0; i < 5; i++) {
    pinMode(rows[i], INPUT_PULLUP);
  }

  for (int i = 0; i < 15; i++) {
    pinMode(columns[i], OUTPUT);
    digitalWrite(columns[i], HIGH);
  }
  
  Keyboard.begin();
}

void updateKeyboard() {
  for (int c = 0; c < 15; c++) {
    digitalWrite(columns[c], LOW);
    
    for (int r = 0; r < 5; r++) {
      bool isPressed = !digitalRead(rows[r]);

      updateKey(r, c, isPressed);
    }
    
    digitalWrite(columns[c], HIGH);
  }
}

void updateKey(int r, int c, bool isPressed) {
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

void pressKey(int r, int c) {
    Key key = getKey(r, c);
    unsigned int code = key.getCode();
    
    downKeys[r][c] = key;
    
    if (code == KEY_NONE || code == KEY_FUNCTION) {
      return;
    } 
    
    if (code == KEY_ACTION) {
      (*actions[key.action][0])();
    } else {
      Keyboard.press(code);
    }
}

struct Key getKey(int r, int c) {
    if (r == 0 && c == 0 && isRightShiftDown()) {
      return tildeKey;
    }

    if (isFnDown()) {
      unsigned int code = keys[FN_LAYER][r][c].getCode();
      return code != KEY_NONE ? keys[FN_LAYER][r][c] : keys[keyLayer][r][c];
    }
    
    return keys[keyLayer][r][c];
}

bool isRightShiftDown() {
  return downKeys[3][12].isDown();
}

bool isFnDown() {
  return downKeys[4][11].isDown();
}

void releaseKey(int r, int c) {
    Key key = downKeys[r][c];
    unsigned int code = key.getCode();
    
    downKeys[r][c].init();
    
    if (code == KEY_NONE || code == KEY_FUNCTION) {
      return;
    }

    if (code == KEY_ACTION) {
      (*actions[key.action][1])();
    } else {
      Keyboard.release(code);
    }
}
