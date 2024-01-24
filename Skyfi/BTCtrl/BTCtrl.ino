
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(12, 13); //rx, tx

void setup() 
{
  pinMode(8, OUTPUT); //R+
  pinMode(9, OUTPUT); //R-
  pinMode(10, OUTPUT); //L+
  pinMode(11, OUTPUT); //L-
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Pair w/ Bluetooth");
}

void moveRobot(String motion)
{
  if(motion=="Forward")
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  if(motion=="Left")
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  if(motion=="Right")
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  if(motion=="Backward")
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  if(motion=="Stop")
  {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}

void loop() 
{
  if(bluetooth.available())
  {
    char bt = bluetooth.read();
    Serial.println("/tCharacter received from the Bluetooth app : " + String(bt));

    if(bt=='8')
    {
      moveRobot("Forward");
    }
    if((bt=='4') || (bt=='E'))
    {
      moveRobot("Left");
    }
    if((bt=='6') || (bt=='F'))
    {
      moveRobot("Right");
    }
    if(bt=='2')
    {
      moveRobot("Backward");
    }
    if(bt=='C')
    {
      moveRobot("Stop");
    }
  }
}
