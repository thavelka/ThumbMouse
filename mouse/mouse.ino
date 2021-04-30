#include<Mouse.h>

#define L_CLICK 10
#define R_CLICK 16
#define STICK_CLICK A1
#define STICK_X A3
#define STICK_Y A2

const int sensitivity = 50;
int xCenter;
int yCenter;
bool lClicked = false;
bool rClicked = false;
bool sClicked = false;

void setup() {
  // put your setup code here, to run once:
  Mouse.begin();
  pinMode(L_CLICK, INPUT_PULLUP);
  pinMode(R_CLICK, INPUT_PULLUP);
  pinMode(STICK_CLICK, INPUT_PULLUP);
  pinMode(STICK_X, INPUT);
  pinMode(STICK_Y, INPUT);

  xCenter = analogRead(STICK_X);
  yCenter = analogRead(STICK_Y);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xVal = analogRead(STICK_X) - xCenter;
  int yVal = analogRead(STICK_Y) - yCenter;
  bool lClick = !digitalRead(L_CLICK);
  bool rClick = !digitalRead(R_CLICK);
  bool sClick = !digitalRead(STICK_CLICK);

  if (xVal > 20) {
    xVal = 1;
  } else if (xVal < -20) {
    xVal = -1;
  } else {
    xVal = 0;
  }

  if (yVal > 20) {
    yVal = 1;
  } else if (yVal < -20) {
    yVal = -1;
  } else {
    yVal = 0;
  }

  if (xVal != 0 || yVal != 0) {
    Mouse.move(xVal, yVal, 0);
  }
 
  if (lClick && !lClicked) {
    Mouse.press(MOUSE_LEFT);
    lClicked = true;
  } else if (!lClick && lClicked) {
    Mouse.release(MOUSE_LEFT);
    lClicked = false;
  }
  if (rClick && !rClicked) {
    Mouse.press(MOUSE_RIGHT);
    rClicked = true;
  } else if (!rClick && rClicked) {
    Mouse.release(MOUSE_RIGHT);
    rClicked = false;
  }
  if (sClick && !sClicked) {
    Mouse.press(MOUSE_LEFT);
    sClicked = true;
  } else if (!sClick && sClicked) {
    Mouse.release(MOUSE_LEFT);
    sClicked = false;
  }

  delay(2);
}
