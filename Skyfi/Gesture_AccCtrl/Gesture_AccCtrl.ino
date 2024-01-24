
void setup() 
{
  pinMode(10, OUTPUT); //R+
  pinMode(11, OUTPUT); //R-
  pinMode(12, OUTPUT); //L+
  pinMode(13, OUTPUT); //L-
  pinMode(A1, INPUT); //x-axis
  pinMode(A2, INPUT); //y-axis
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
  if(motion=="Backward")
  {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
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
  int x = analogRead(A1);
  int y = analogRead(A2);  

  Serial.println("\tX-axis: " + String(x) + "\tY-axis: " + String(y));
  delay(1000);
  
  if(x < 300) //FW
  {
    moveRobot("Forward");
  }
  if(y < 300) //LT 
  {
    moveRobot("Left");
  }
  if( ((x>300) && (x<350)) && ((y>300) && (y<350))) //Stop 
  {
    moveRobot("Stop");
  }
  if(y > 350) //RT
  {
    moveRobot("Right");
  }
  if(x > 350) //BW
  {
    moveRobot("Backward");
  }
}
