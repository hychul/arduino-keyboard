#define pinCLK 2 // Connected pin number to CLK on KY-040
#define pinDT 3 // Connected pin numbder to DT on KY-040
#define pinSW 4 // Connected pin numbder to SW on KY-040
#define minSwitchMs 100 // 

void setup() {
  setupRotary();
}

void loop() {
  readRotary();
  readSwitch();
}

int lastRotaryVal;
boolean isClockwise;
int encoderPosCount = 0;

int lastSwitchVal;
unsigned long lastSwitchMs = 0;

void setupRotary() {
  pinMode(pinCLK,INPUT);
  pinMode(pinDT,INPUT);
  pinMode(pinSW,INPUT);
  
  lastRotaryVal = digitalRead(pinCLK);
  lastSwitchVal = digitalRead(pinSW);
  
  Serial.begin(9600);
}

void readRotary() {
  int val = digitalRead(pinCLK);

  if (val == lastRotaryVal) {
    return;
  }
  
  if (digitalRead(pinDT) != val) {
    isClockwise = true;
    encoderPosCount ++;
  } else {
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
  
  lastRotaryVal = val;
}


void readSwitch() {
  int val = digitalRead(pinSW);

  if (val == lastSwitchVal) {
    return;
  }

  if (millis() < lastSwitchMs + minSwitchMs) {
    return;
  }

  Serial.print("Switch: ");
  if (val == LOW) {
    Serial.println("pushed");
  } else {
    Serial.println("released");
  }

  lastSwitchVal = val;
  lastSwitchMs = millis();
}
