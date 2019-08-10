#include <Keyboard.h>
#include <Mouse.h>

#define PIN1  10
#define PIN2  16
#define PIN3  14
#define PIN4  15
#define PIN5  7
#define PIN6  9
#define PIN7  4
#define PIN8  5
#define PIN9  6
#define PIN10 A3 
#define PIN11 A2
#define PIN12 A1

#define SWITCH  A0
#define LEDSWITCH 8
#define LEDOUT 2
#define KEYBOARDOFFSWITCH 3

int readyRelease1 = 0;
int readyRelease2 = 0;
int readyRelease3 = 0;
int readyRelease4 = 0;
int readyRelease5 = 0;
int readyRelease6 = 0;
int readyRelease7 = 0;
int readyRelease8 = 0;
int readyRelease9 = 0;
int readyRelease10 = 0;
int readyRelease11 = 0;
int readyRelease12 = 0;

int randomNum = 0;

void pressReleaseCheck() { // Keypads set 1 is currently numbers. Edit both Keyboard.press(es) and Keyboard.release(s) on pin to change what pressing on button does
  if (digitalRead(PIN1) == LOW) {
    Keyboard.press('1');
    readyRelease1 = 1;
  }
  if (digitalRead(PIN2) == LOW) {
    Keyboard.press('2');
    readyRelease2 = 1;
  }
  if (digitalRead(PIN3) == LOW) {
    Keyboard.press('3');
    readyRelease3 = 1;
  }

  if (digitalRead(PIN4) == LOW) {
    Keyboard.press('4');
    readyRelease4 = 1;
  }
  if (digitalRead(PIN5) == LOW) {
    Keyboard.press('5');
    readyRelease5 = 1;
  }
  if (digitalRead(PIN6) == LOW) {
    Keyboard.press('6');
    readyRelease6 = 1;
  }

  if (digitalRead(PIN7) == LOW) {
    Keyboard.press('7');
    readyRelease7 = 1;
  }
  if (digitalRead(PIN8) == LOW) {
    Keyboard.press('8');
    readyRelease8 = 1;
  }
  if (digitalRead(PIN9) == LOW) {
    Keyboard.press('9');
    readyRelease9 = 1;
  }

  if (digitalRead(PIN10) == LOW) {
    Keyboard.press('0');
    readyRelease10 = 1;
  }
  if (digitalRead(PIN11) == LOW) {
    randomNum = random(1,3);
    while(digitalRead(PIN11) == LOW) {
      Mouse.click();
      if (randomNum == 1) {
        delay(random(100, 120));
      } else if (randomNum == 1) {
        delay(random(90, 110));
      } else {
        delay(random(80, 100));
      }
    }
    Mouse.release();
//    Keyboard.press(KEY_LEFT_CTRL);
//    Keyboard.press(KEY_LEFT_GUI);
//    Keyboard.press('c');
//    readyRelease11 = 1;
  }
  if (digitalRead(PIN12) == LOW) {
    while(digitalRead(PIN12) == LOW) {
      Keyboard.press(32);
    }
    Keyboard.release(32);
//    Keyboard.press(KEY_LEFT_CTRL);
//    Keyboard.press(KEY_LEFT_GUI);
//    Keyboard.press('v');
//    readyRelease12 = 1;
  }

  ///

  if (readyRelease1 && digitalRead(PIN1)) {
    Keyboard.release('1');
    readyRelease1 = 0;
  }
  if (readyRelease2 && digitalRead(PIN2)) {
    Keyboard.release('2');
    readyRelease2 = 0;
  }
  if (readyRelease3 && digitalRead(PIN3)) {
    Keyboard.release('3');
    readyRelease3 = 0;
  }

  if (readyRelease4 && digitalRead(PIN4)) {
    Keyboard.release('4');
    readyRelease4 = 0;
  }
  if (readyRelease5 && digitalRead(PIN5)) {
    Keyboard.release('5');
    readyRelease5 = 0;
  }
  if (readyRelease6 && digitalRead(PIN6)) {
    Keyboard.release('6');
    readyRelease6 = 0;
  }

  if (readyRelease7 && digitalRead(PIN7)) {
    Keyboard.release('7');
      readyRelease7 = 0;
  }
  if (readyRelease8 && digitalRead(PIN8)) {
    Keyboard.release('8');
    readyRelease8 = 0;
  }
  if (readyRelease9 && digitalRead(PIN9)) {
    Keyboard.release('9');
    readyRelease9 = 0;
  }

  if (readyRelease10 && digitalRead(PIN10)) {
     Keyboard.release('0');
     readyRelease10 = 0;
  }
  if (readyRelease11 && digitalRead(PIN11)) {
//    Keyboard.release(KEY_LEFT_CTRL);
//    Keyboard.release(KEY_LEFT_GUI);
//    Keyboard.release('c');
//    readyRelease11 = 0;
  }
  if (readyRelease12 && digitalRead(PIN12)) {
//    Keyboard.release(KEY_LEFT_CTRL);
//    Keyboard.release(KEY_LEFT_GUI);
//    Keyboard.release('v');
//    readyRelease12 = 0;
  }
}


void pressReleaseCheck2() { // Keypads set 2 is currently f1-f12. Edit both Keyboard.press(es) and Keyboard.release(s) on pin to change what pressing on button does
  if (digitalRead(PIN1) == LOW) {
    Keyboard.press(KEY_F1);
    while(digitalRead(PIN1) == LOW){}
    readyRelease1 = 1;
  }
  if (digitalRead(PIN2) == LOW) {
    Keyboard.press(KEY_F2);
    while(digitalRead(PIN2) == LOW){}
    readyRelease2 = 1;
  }
  if (digitalRead(PIN3) == LOW) {
    Keyboard.press(KEY_F3);
    while(digitalRead(PIN3) == LOW){}
    readyRelease3 = 1;
  }

  if (digitalRead(PIN4) == LOW) {
    Keyboard.press(KEY_F4);
    while(digitalRead(PIN4) == LOW){}
    readyRelease4 = 1;
  }
  if (digitalRead(PIN5) == LOW) {
    Keyboard.press(KEY_F5);
    while(digitalRead(PIN5) == LOW){}
    readyRelease5 = 1;
  }
  if (digitalRead(PIN6) == LOW) {
    Keyboard.press(KEY_F6);
    while(digitalRead(PIN6) == LOW){}
    readyRelease6 = 1;
  }

  if (digitalRead(PIN7) == LOW) {
    Keyboard.press(KEY_F7);
    while(digitalRead(PIN7) == LOW){}
    readyRelease7 = 1;
  }
  if (digitalRead(PIN8) == LOW) {
    Keyboard.press(KEY_F8);
    while(digitalRead(PIN8) == LOW){}
    readyRelease8 = 1;
  }
  if (digitalRead(PIN9) == LOW) {
    Keyboard.press(KEY_F9);
    while(digitalRead(PIN9) == LOW){}
    readyRelease9 = 1;
  }

  if (digitalRead(PIN10) == LOW) {
    Keyboard.press(KEY_F10);
    while(digitalRead(PIN10) == LOW){}
    readyRelease10 = 1;
  }
  if (digitalRead(PIN11) == LOW) {
    Keyboard.press(KEY_F11);
    while(digitalRead(PIN11) == LOW){}
    readyRelease11 = 1;
  }
  if (digitalRead(PIN12) == LOW) {
    Keyboard.press(KEY_F12);
    while(digitalRead(PIN12) == LOW){}
    readyRelease12 = 1;
  }

  ///

  if (readyRelease1 && digitalRead(PIN1)) {
    Keyboard.release(KEY_F1);
    readyRelease1 = 0;
  }
  if (readyRelease2 && digitalRead(PIN2)) {
    Keyboard.release(KEY_F2);
    readyRelease2 = 0;
  }
  if (readyRelease3 && digitalRead(PIN3)) {
    Keyboard.release(KEY_F3);
    readyRelease3 = 0;
  }

  if (readyRelease4 && digitalRead(PIN4)) {
    Keyboard.release(KEY_F4);
    readyRelease4 = 0;
  }
  if (readyRelease5 && digitalRead(PIN5)) {
    Keyboard.release(KEY_F5);
    readyRelease5 = 0;
  }
  if (readyRelease6 && digitalRead(PIN6)) {
    Keyboard.release(KEY_F6);
    readyRelease6 = 0;
  }

  if (readyRelease7 && digitalRead(PIN7)) {
    Keyboard.release(KEY_F7);
    readyRelease7 = 0;
  }
  if (readyRelease8 && digitalRead(PIN8)) {
    Keyboard.release(KEY_F8);
    readyRelease8 = 0;
  }
  if (readyRelease9 && digitalRead(PIN9)) {
    Keyboard.release(KEY_F9);
    readyRelease9 = 0;
  }

  if (readyRelease10 && digitalRead(PIN10)) {
     Keyboard.release(KEY_F10);
     readyRelease10 = 0;
  }
  if (readyRelease11 && digitalRead(PIN11)) {
    Keyboard.release(KEY_F11);
    readyRelease11 = 0;
  }
  if (readyRelease12 && digitalRead(PIN12)) {
    Keyboard.release(KEY_F12);
    readyRelease12 = 0;
  }
}


//
void setup() {
  pinMode(PIN1, INPUT_PULLUP);
  pinMode(PIN2, INPUT_PULLUP);
  pinMode(PIN3, INPUT_PULLUP);
  pinMode(PIN4, INPUT_PULLUP);
  pinMode(PIN5, INPUT_PULLUP);
  pinMode(PIN6, INPUT_PULLUP);
  pinMode(PIN7, INPUT_PULLUP);
  pinMode(PIN8, INPUT_PULLUP);
  pinMode(PIN9, INPUT_PULLUP);
  pinMode(PIN10, INPUT_PULLUP);
  pinMode(PIN11, INPUT_PULLUP);
  pinMode(PIN12, INPUT_PULLUP);
  pinMode(SWITCH, INPUT_PULLUP);
  pinMode(LEDSWITCH, INPUT_PULLUP);
  pinMode(LEDOUT, OUTPUT);
  pinMode(KEYBOARDOFFSWITCH, INPUT_PULLUP);
  
  Keyboard.begin();

  Mouse.begin();
}
void loop() {
  if (digitalRead(SWITCH)) {
    pressReleaseCheck();  // Keypads set 1
  } else {
    pressReleaseCheck2(); // Keypads set 2
  }
  if (digitalRead(LEDSWITCH)) { // Switch LEDS on or off
    digitalWrite(LEDOUT, LOW);
  } else {
    digitalWrite(LEDOUT, HIGH);
  }

  if (digitalRead(KEYBOARDOFFSWITCH)) {
    Keyboard.releaseAll();
    Mouse.release();
    Keyboard.end();
    Mouse.end();
    while(digitalRead(KEYBOARDOFFSWITCH)) {
      if (digitalRead(LEDSWITCH)) { // Switch LEDS on or off
        digitalWrite(LEDOUT, LOW);
      } else {
        digitalWrite(LEDOUT, HIGH);
      }
    }
    Keyboard.begin();
  }
  
}
