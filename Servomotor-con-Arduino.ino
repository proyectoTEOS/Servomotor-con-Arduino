/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/

#include <Servo.h>

Servo servoT;

const int pinServoT =  3;
int positionServoT = 0; 
boolean forwardT = false; 
unsigned long timeAccountingT = millis();
const int setBackT = 20;

void setup() {
  servoT.attach(pinServoT); 
}

void loop () {
  if (millis () - timeAccountingT >= setBackT) {
    timeAccountingT += setBackT ;
    if (forwardT) {
      servoT.write(-- positionServoT);
      if (positionServoT == 0)
        forwardT = false ;
    }
    else {
      servoT.write (++ positionServoT);
      if (positionServoT == 180)
        forwardT = true ;
    }
  }
}
