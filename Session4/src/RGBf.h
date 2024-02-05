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