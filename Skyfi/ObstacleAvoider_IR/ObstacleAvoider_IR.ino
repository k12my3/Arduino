
void setup() 
{
  pinMode(10, OUTPUT); // R+
  pinMode(11, OUTPUT); // R-
  pinMode(12, OUTPUT); // L+
  pinMode(13, OUTPUT); // L-
  pinMode(A0, INPUT); // R-sens
  pinMode(A1, INPUT); // L-sens
}

void moveRobot(String motion)
{
  if(motion=="Forward")
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  if(motion=="Backward")
  {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  if(motion=="Left")
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  if(motion=="Right")
  {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  if(motion=="Stop")
  {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
}

void loop() 
{
  int Right = analogRead(A0);
  int Left = analogRead(A1);
  
  if((Right > 600) && (Left > 600)) // both obstacle
  {
    moveRobot("Stop");
    delay(1000);
    moveRobot("Backward");
    delay(1000);
    moveRobot("Left");
    delay(2000);
  }
  if((Right < 600) && (Left < 600)) // both no obstacle
  {
    moveRobot("Forward");
  }
  if((Right < 600) && (Left > 600)) // left obstacle
  {
    moveRobot("Stop");
    delay(1000);
    moveRobot("Backward");
    delay(1000);
    moveRobot("Right");
    delay(1000);
  }
  if((Right > 600) && (Left < 600)) // right obstacle
  {
    moveRobot("Stop");
    delay(1000);
    moveRobot("Backward");
    delay(1000);
    moveRobot("Left");
    delay(1000);
  }
}
