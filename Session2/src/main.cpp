#include <Arduino.h>


void generateSquareWave(int pin, int frequency, int duration){
  unsigned long delayTime = 1000000 / (2 * frequency);
  unsigned long numberOfRepeat = (duration * 1000) / (2 * delayTime);

  for (unsigned long i = 0; i < numberOfRepeat; i++){
    digitalWrite(pin, 1);
    delayMicroseconds(delayTime);
    digitalWrite(pin, 0);
    delayMicroseconds(delayTime);
  }

}


// put function declarations here:
int myFunction(int, int);

void setup() {
  pinMode(9, OUTPUT);
  pinMode(7, INPUT);
}

void loop() {
  // if(digitalRead(7)){
  //   digitalWrite(9, HIGH);
  //   delay(100);
  //   digitalWrite(9, LOW);
  //   delay(100);
  // }else{
  //   digitalWrite(9, LOW);
  // }
  // digitalWrite(9, digitalRead(7));
  generateSquareWave(9, 1000, 3000);
  digitalWrite(9, 0);
  delay(1000);
}


