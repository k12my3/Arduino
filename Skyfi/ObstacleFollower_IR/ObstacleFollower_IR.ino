
//right sens - A0, left sens - A1

void setup() 
{
  pinMode(10, OUTPUT); //R+
  pinMode(11, OUTPUT); //R-
  pinMode(12, OUTPUT); //L+
  pinMode(13, OUTPUT); //L-
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);  
  //Serial.begin(9600);
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
  //Serial.println("Value of Right Sensor: " + String(Right) + "\tValue of Left Sensor: " + String(Left));
  //delay(1000);

  if((Right > 800) && (Left > 800)) // both black  / no obstacle : original : <, <
  {
    moveRobot("Stop");
  }
  if((Right < 800) && (Left < 800)) // both white / obstacle : or : > , > 
  {
    moveRobot("Forward");
  }
  if((Right < 800) && (Left > 800)) //r - white / r - obstacle : or : > , < 
  {
    moveRobot("Right");
  }
  if((Right > 800) && (Left < 800)) //l - white / l - obstacle : or : < , > 
  {
    moveRobot("Left");
  }
}
