// Positives:
// 0  1  2  3  4  5  6  7 (rows) -> HIGH to turn ON
// A5 A4 A3 A2 A1 A0 8  9 (columns) -> LOW to turn ON

const int row[] = {0, 1,  2,  3,  4,  5,  6,  7 };
const int col[] = {A5, A4, A3, A2, A1, A0, 8,  9};
const int up = 10;
const int down = 11;
const int left = 12;
const int right = 13;

int ledPos[] = {3, 3};

void setup() {
  
  for (int i = 0; i < 8; i++) {
    pinMode(row[i], OUTPUT);
    pinMode(col[i], OUTPUT);
  }

  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  
  turnOffAll();
}

void loop() {
  moveLED();
  turnOneLED(0,0);
  turnOneLED(7,7);
  turnOneLED(0,7);
  turnOneLED(7,0);

  if ((ledPos[0] == 0) && (ledPos[1] == 0)) {
    loopThroughMatrix(100);
    ledPos[0] = 3;
    ledPos[1] = 3;
    moveLED();
  }
  else if ((ledPos[0] == 0) && (ledPos[1] == 7)) {
    loopThroughMatrix2(100);
    ledPos[0] = 3;
    ledPos[1] = 3;
    moveLED();
  }
  else if ((ledPos[0] == 7) && (ledPos[1] == 0)) {
    for (int i = 0; i < 7; i++) {
      swirlOut(200);
    }
    ledPos[0] = 3;
    ledPos[1] = 3;
    moveLED();
  }
  else if ((ledPos[0] == 7) && (ledPos[1] == 7)) {
    iLovU(500);
    ledPos[0] = 3;
    ledPos[1] = 3;
    moveLED();
  }
}


//=========Functions============//

// turn off all LEDs
void turnOffAll() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(row[i], LOW);
    digitalWrite(col[i], HIGH);
  }
}

// turns on one LED, turns off rest. 
// First row or col is 0
void turnOneLED(int c, int r) {
  turnOffAll();
  digitalWrite(row[r], HIGH);
  digitalWrite(col[c], LOW);
}

// Check that all LEDs light up
void loopThroughMatrix(int delayAmount) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0 ; j < 8; j++) {
      turnOneLED(j, i);
      delay(delayAmount);
    }
  }
}

// Check that all LEDs light up
void loopThroughMatrix2(int delayAmount) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0 ; j < 8; j++) {
      turnOneLED(i, j);
      delay(delayAmount);
    }
  }
}

// swirl out pattern
void swirlOut(int delayAmount) {
  
  // first square
  long timeStart = millis();
  while ((millis() - timeStart) < delayAmount) {
    turnOneLED(4, 3);
    turnOneLED(4, 4);
    turnOneLED(3, 3);
    turnOneLED(3, 4);
  }

  // second circle
  timeStart = millis();
  while((millis() - timeStart) < delayAmount) {
    turnOneLED(3,2);
    turnOneLED(4,2);
    turnOneLED(2,3);
    turnOneLED(2,4);
    turnOneLED(5,3);
    turnOneLED(5,4);
    turnOneLED(3,5);
    turnOneLED(4,5);
  }


  // third circle
  timeStart = millis();
  while((millis() - timeStart) < delayAmount) {
    turnOneLED(1,3);
    turnOneLED(2,2);
    turnOneLED(3,1);
    turnOneLED(4,1);
    turnOneLED(5,2);
    turnOneLED(6,3);
    turnOneLED(6,4);
    turnOneLED(5,5);
    turnOneLED(4,6);
    turnOneLED(3,6);
    turnOneLED(2,5);
    turnOneLED(1,4);
  }
}

void iLovU(int delayAmount) {
  long timeStart = millis();
  while ((millis() - timeStart) < delayAmount) {
    turnOneLED(2,1);
    turnOneLED(3,1);
    turnOneLED(4,1);
    turnOneLED(5,1);
  
    turnOneLED(3,2);
    turnOneLED(4,2);
    turnOneLED(3,3);
    turnOneLED(4,3);
    turnOneLED(3,4);
    turnOneLED(4,4);
    turnOneLED(3,5);
    turnOneLED(4,5);

    turnOneLED(2,6);
    turnOneLED(3,6);
    turnOneLED(4,6);
    turnOneLED(5,6);
  }

  timeStart = millis();
  while ((millis() - timeStart) < delayAmount) {
    turnOneLED(3,2);
    turnOneLED(4,2);

    turnOneLED(2,1);
    turnOneLED(5,1);

    turnOneLED(1,2);
    turnOneLED(6,2);
    turnOneLED(1,3);
    turnOneLED(6,3);

    turnOneLED(2,4);
    turnOneLED(5,4);
    turnOneLED(3,5);
    turnOneLED(4,5);
  }

  timeStart = millis();
  while ((millis() - timeStart) < delayAmount) {
    turnOneLED(3,6);
    turnOneLED(4,6);

    turnOneLED(2,1);
    turnOneLED(2,2);
    turnOneLED(2,3);
    turnOneLED(2,4);
    turnOneLED(2,5);
    turnOneLED(5,1);
    turnOneLED(5,2);
    turnOneLED(5,3);
    turnOneLED(5,4);
    turnOneLED(5,5);
    
  }
}

void moveLED() {
  turnOneLED(ledPos[0], ledPos[1]);
  if((digitalRead(right) == LOW) && (ledPos[0] < 7)) {
    ledPos[0]++;
    while(digitalRead(right) == LOW) {
      turnOneLED(0,0);
      turnOneLED(7,7);
      turnOneLED(0,7);
      turnOneLED(7,0);
      turnOneLED(ledPos[0], ledPos[1]);
    }
  }
  if((digitalRead(left) == LOW) && (ledPos[0] > 0)) {
    ledPos[0]--;
    while(digitalRead(left) == LOW) {
      turnOneLED(0,0);
      turnOneLED(7,7);
      turnOneLED(0,7);
      turnOneLED(7,0);
      turnOneLED(ledPos[0], ledPos[1]);
    }
  }
  if((digitalRead(up) == LOW) && (ledPos[1] < 7)) {
    ledPos[1]++;
    while(digitalRead(up) == LOW) {
      turnOneLED(0,0);
      turnOneLED(7,7);
      turnOneLED(0,7);
      turnOneLED(7,0);
      turnOneLED(ledPos[0], ledPos[1]);
    }
  }
  if((digitalRead(down) == LOW) && (ledPos[1] > 0)) {
    ledPos[1]--;
    while(digitalRead(down) == LOW) {
      turnOneLED(0,0);
      turnOneLED(7,7);
      turnOneLED(0,7);
      turnOneLED(7,0);
      turnOneLED(ledPos[0], ledPos[1]);
    }
  }
}

