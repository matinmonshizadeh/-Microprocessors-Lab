#include <Arduino.h>

// put function declarations here:
#define LEDPIN1 12
#define LEDPIN2 11

unsigned long tOn = 4;
unsigned long tOff = 1;

void setup() {
  pinMode(LEDPIN1, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
}




void loop() {
  digitalWrite(LEDPIN1, 0);
  digitalWrite(LEDPIN2, 1);
  delay(tOn);
  digitalWrite(LEDPIN1, 1);
  digitalWrite(LEDPIN2, 0 );
  delay(tOff);
  //
}
