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
