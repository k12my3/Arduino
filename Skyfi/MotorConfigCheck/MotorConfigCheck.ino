
//right sens - A0, left sens - A1

void setup() 
{
  pinMode(10, OUTPUT); //R+
  pinMode(11, OUTPUT); //R-
  pinMode(12, OUTPUT); //L+
  pinMode(13, OUTPUT); //L-
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);  
  Serial.begin(9600);
}

void moveRobot(String motion)
{
  if(motion=="Forward")
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    Serial.println("Forward");
  }
  if(motion=="Backward")
  {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    Serial.println("Backward");
  }
  if(motion=="Left")
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    Serial.println("Left");
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
    Serial.println("Stop");
  }
}

void loop() 
{
  int Right = analogRead(A0);
  int Left = analogRead(A1);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
    moveRobot("Forward"); delay(5000);
    moveRobot("Backward"); delay(5000);
    moveRobot("Right"); delay(5000);
    moveRobot("Left"); delay(5000);
    moveRobot("Stop"); delay(5000);
}