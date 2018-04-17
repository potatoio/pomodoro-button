// You know the routine by now, just going to comment on the new things!

#include "InternetButton.h"

SYSTEM_MODE(SEMI_AUTOMATIC);

InternetButton b = InternetButton();

int ledCount = 11;
int MILSEC_TO_MIN = 60000;

void setup() {
    b.begin();

    b.playSong("C4,8,E4,8,G4,8,C5,8,G5,4");
}

int convertMilToSec(int milsec) {
  return milsec * MILSEC_TO_MIN;
}

void pomodoro(int time) {
  for(int i=1; i<=ledCount; i++) {
    b.ledOn(i, 0, 255, 0);
    delay(convertMilToSec(time) / ledCount);
  }

  b.allLedsOff();
  b.playSong("C4,8,E4,8,G4,8,C5,8,G5,4");
}

void loop() {

  if(b.buttonOn(1)) {
    pomodoro(2);
  }

  if(b.buttonOn(2)) {
    pomodoro(5);
  }

  if(b.buttonOn(3)) {
    pomodoro(10);
  }

  if(b.buttonOn(4)) {
    pomodoro(25);
  }

}
