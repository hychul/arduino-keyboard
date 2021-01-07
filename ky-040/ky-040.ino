void setup() {
  setupRotary();
}

void loop() {
  readRotary();
}

int pinA = 3; // Connected pin number to CLK on KY-040
int pinB = 4; // Connected pin numbder to DT on KY-040

int lastVal;
boolean isClockwise;
int encoderPosCount = 0;

void setupRotary() {
  pinMode(pinA,INPUT);
  pinMode(pinB,INPUT);
  // Read Pin A
  // Whatever state it's in will reflect the last position
  lastVal = digitalRead(pinA);
  Serial.begin(9600);
}

void readRotary() {
  int aVal = digitalRead(pinA);

  if (aVal == lastVal) {
    return;
  }
  
  // Means the knob is rotating
  // If the knob is rotating, we need to determine direction
  // We do that by reading pin B.
  if (digitalRead(pinB) != aVal) { // Means pin A Changed first - We're Rotating Clockwise
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
  lastVal = aVal;
}
