
void setup() 
{
  pinMode(10, OUTPUT); //R+
  pinMode(11, OUTPUT); //R-
  pinMode(12, OUTPUT); //L+
  pinMode(13, OUTPUT); //L-
  pinMode(4, INPUT); //D0
  pinMode(5, INPUT); //D1
  pinMode(6, INPUT); //D2
  pinMode(7, INPUT); //D3
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
  int D0 = digitalRead(4);
  int D1 = digitalRead(5);
  int D2 = digitalRead(6);
  int D3 = digitalRead(7);  

  Serial.println("\tD3: " + String(D3) + "\tD2: " + String(D2) + "\tD1: " + String(D1) + "\tD0: " + String(D0));
  delay(1000);
  
  if((D3==0) && (D2==0) && (D1==1) && (D0==0)) // num2 - FW
  {
    moveRobot("Forward");
    Serial.print("Forward - ");
  }
  if((D3==0) && (D2==1) && (D1==0) && (D0==0)) // num4 - LT 
  {
    moveRobot("Left");
    Serial.print("Left - ");
  }
  if((D3==0) && (D2==1) && (D1==0) && (D0==1)) // num5 - Stop 
  {
    moveRobot("Stop");
    Serial.print("Stop - ");
  }
  if((D3==0) && (D2==1) && (D1==1) && (D0==0)) // num6 - RT
  {
    moveRobot("Right");
    Serial.print("Right - ");
  }
  if((D3==1) && (D2==0) && (D1==0) && (D0==0)) // num8 - BW
  {
    moveRobot("Backward");
    Serial.print("Backward - ");
  }
}
