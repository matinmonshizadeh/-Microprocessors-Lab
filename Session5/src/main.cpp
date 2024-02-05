#include <Arduino.h>


void setup() {
  Serial.begin(9600);
  pinMode(GPIO_NUM_25, OUTPUT);
  pinMode(GPIO_NUM_26, OUTPUT);
}

bool stateGreen = false;
unsigned long previousTimeGreen = 0;
bool stateYellow = false;
unsigned long previousTimeYellow = 0;
void loop() {
  
  unsigned long t = millis();
  // digitalWrite(GPIO_NUM_25, HIGH);
  // digitalWrite(GPIO_NUM_26, HIGH);
  // delay(1000);
  // digitalWrite(GPIO_NUM_26, LOW);
  // delay(1000);
  // digitalWrite(GPIO_NUM_25, LOW);
  // digitalWrite(GPIO_NUM_26, HIGH);
  // delay(1000);
  // digitalWrite(GPIO_NUM_26, LOW);
  // delay(1000);


  // if (t % 10000 < 5000) {
  //   digitalWrite(GPIO_NUM_25, HIGH);
  // } else {
  //   digitalWrite(GPIO_NUM_25, LOW);
  // }

  unsigned long currentTimeGreen = millis();
  unsigned long currentTimeYellow = millis();
  if(currentTimeGreen - previousTimeGreen > 1000) {
    previousTimeGreen = currentTimeGreen;
    stateGreen = !stateGreen;
    digitalWrite(GPIO_NUM_25, stateGreen);
  }
  if(currentTimeYellow - previousTimeYellow > 27) {
    previousTimeYellow = currentTimeYellow;
    stateYellow = !stateYellow;
    digitalWrite(GPIO_NUM_26, stateYellow);
  }

  // Serial.println(t);
}

