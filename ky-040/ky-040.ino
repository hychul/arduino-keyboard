void setup() {
  setupRotary();
}

void loop() {
  readRotary();
  readSwitch();
}

int pinCLK = 2; // Connected pin number to CLK on KY-040
int pinDT = 3; // Connected pin numbder to DT on KY-040
int pinSW = 4; // Connected pin numbder to SW on KY-040

int lastVal;
boolean isClockwise;
int encoderPosCount = 0;

void setupRotary() {
  pinMode(pinCLK,INPUT);
  pinMode(pinDT,INPUT);
  pinMode(pinSW,INPUT);
  
  // Read Pin A
  // Whatever state it's in will reflect the last position
  lastVal = digitalRead(pinCLK);
  
  Serial.begin(9600);
}

void readRotary() {
  int clkVal = digitalRead(pinCLK);

  if (clkVal == lastVal) {
    return;
  }
  
  // Means the knob is rotating
  // If the knob is rotating, we need to determine direction
  // We do that by reading pin B.
  if (digitalRead(pinDT) != clkVal) { // Means pin A Changed first - We're Rotating Clockwise
    isClockwise = true;
    encoderPosCount ++;
  } else { // Otherwise B changed first and we're moving CCW
    isClockwise = false;
    encoderPosCount--;
  }
  
  Serial.print("Rotated: ");
  if (isClockwise) {
    Serial.println("clockwise");
  } else {
    Serial.println("counterclockwise");
  }
  Serial.print("Encoder Position: ");
  Serial.println(encoderPosCount);
  lastVal = clkVal;
}


void readSwitch() {
  int swVal = digitalRead(pinSW);

  if (swVal == LOW) {
    Serial.println("switch pushed");
  }
}
