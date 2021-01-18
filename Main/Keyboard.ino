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

  for (int i = 0; i < 8; i++) {
    shift.writeBit(shiftyColumns[i], HIGH);
  }

  for (int i = 0; i < 7; i++) {
    pinMode(columns[i], OUTPUT);
    digitalWrite(columns[i], HIGH);
  }
  
  Keyboard.begin();
}

void updateKeyboard() {
  for (int c = 0; c < 8; c++) {
    shift.writeBit(shiftyColumns[c], LOW);
    
    for (int r = 0; r < 5; r++) {
      bool isPressed = !digitalRead(rows[r]);

      updateKey(r, c, isPressed);
    }
    
    shift.writeBit(shiftyColumns[c], HIGH);
  }
  
  for (int c = 0; c < 7; c++) {
    digitalWrite(columns[c], LOW);
    
    for (int r = 0; r < 5; r++) {
      bool isPressed = !digitalRead(rows[r]);

      updateKey(r, c + 8, isPressed);
    }
    
    digitalWrite(columns[c], HIGH);
  }
}

void writeDigitalBit(int pin) {
  
}

void updateKey(int r, int c, bool isPressed) {
  bool isChanged = isPressed != downKeys[r][c].isDown();
    Serial.println("key update");

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
    unsigned char ch = key.getCh();
    
    downKeys[r][c] = key;
    
    if (ch == KEY_NONE || ch == KEY_FUNCTION) {
      return;
    } 
    
    if (ch == KEY_ACTION) {
      (*actions[key.action][0])();
    } else {
      Keyboard.press(ch);
    }
}

struct Key getKey(int r, int c) {
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

void releaseKey(int r, int c) {
    Key key = downKeys[r][c];
    unsigned char ch = key.getCh();
    
    downKeys[r][c].init();
    
    if (ch == KEY_NONE || ch == KEY_FUNCTION) {
      return;
    }

    if (ch == KEY_ACTION) {
      (*actions[key.action][1])();
    } else {
      Keyboard.release(ch);
    }
}
