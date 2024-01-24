void setup() 
{
 pinMode(10, OUTPUT); //+ve of DC
 pinMode(11, OUTPUT); //-ve of DC
}

void loop() 
{
  //CW : 10 - LOW, 11 - HIGH | CCW : 10 - HIGH, 11 - LOW
 
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(3000);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(3000);
}
