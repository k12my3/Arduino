
//right sens - A0, left sens - A1

void setup() 
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);  
//  Serial.begin(9600);
}

void moveRobot(String motion)
{
  if(motion=="Forward")
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    //Serial.println("Forward");
  }
  /*if(motion=="Backward")
  {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    Serial.println("Backward");
  }*/
  if(motion=="Left")
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    //Serial.println("Left");
  }
  if(motion=="Right")
  {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    Serial.println("Right");
  }
  if(motion=="Stop")
  {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    //Serial.println("Stop");
  }
}

void loop() 
{
  int Right = analogRead(A0);
  int Left = analogRead(A1);
  Serial.println("Value of Right Sensor: " + String(Right) + "\tValue of Left Sensor: " + String(Left));
  delay(1000);

  if((Right > 600) && (Left > 600)) // both white
  {
    moveRobot("Forward");
  }
  if((Right < 600) && (Left < 600)) // both black
  {
    moveRobot("Stop");
  }
  if((Right < 600) && (Left > 600)) //r - black
  {
    moveRobot("Right");
  }
  if((Right > 600) && (Left < 600)) //l - black
  {
    moveRobot("Left");
  }
  
 /* moveRobot("Forward");
  delay(3000);
  moveRobot("Backward");
  delay(3000);
  moveRobot("Left");
  delay(3000);
  moveRobot("Right");
  delay(3000);
  moveRobot("Stop");
  delay(3000);*/
}
