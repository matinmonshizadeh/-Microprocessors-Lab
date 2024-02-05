#include <Arduino.h>
#define REDPIN 9
#define GREENPIN 10
#define BLUEPIN 11





void RGBSetup(int redPin, int greenPin, int bluePin){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void RGBSetColor(String color, int redPin, int greenPin, int bluePin)
{
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(redPin, LOW);
  if (color.equals("RED"))
  {
    digitalWrite(redPin, HIGH);
  }else if(color.equals("GREEN")){
    digitalWrite(greenPin, HIGH);
  }else if(color.equals("BLUE")){
    digitalWrite(bluePin, HIGH);
  }
}


void setup() {
  Serial.begin(9600);
  Serial.println("Hello World!");
}

void loop() {

  // RGBSetColor("RED", REDPIN, GREENPIN, BLUEPIN);
  // delay(500);
  // RGBSetColor("GREEN", REDPIN, GREENPIN, BLUEPIN);
  // delay(500);
  // RGBSetColor("BLUE", REDPIN, GREENPIN, BLUEPIN);
  // delay(500);

  // digitalWrite(BLUEPIN, HIGH);
  // digitalWrite(REDPIN, HIGH);
  // delay(500);
  // digitalWrite(BLUEPIN, LOW);
  // digitalWrite(REDPIN, LOW);

  // digitalWrite(BLUEPIN, HIGH);
  // digitalWrite(GREENPIN, HIGH);
  // delay(500);
  // digitalWrite(BLUEPIN, LOW);
  // digitalWrite(GREENPIN, LOW);

  // digitalWrite(REDPIN, HIGH);
  // digitalWrite(GREENPIN, HIGH);
  // delay(500);
  // digitalWrite(REDPIN, LOW);
  // digitalWrite(GREENPIN, LOW);

  // digitalWrite(REDPIN, HIGH);
  // digitalWrite(BLUEPIN, HIGH);
  // digitalWrite(GREENPIN, HIGH);
  // delay(500);
  // digitalWrite(REDPIN, LOW);
  // digitalWrite(BLUEPIN, LOW);
  // digitalWrite(GREENPIN, LOW);

  // analogWrite(REDPIN, 98);
  // analogWrite(GREENPIN, 172);
  // analogWrite(BLUEPIN, 141);

  Serial.println(analogRead(A0));
  delay(500);

}





