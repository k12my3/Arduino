int mot1 =8;
int mot2 =9;
int mot3 =10;
int mot4 =11;
void setup()
{
  pinMode(mot1,OUTPUT);
    pinMode(mot2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);
  //pinMode(mot1,OUTPUT);

}
void loop()
{
  //forward:
  digitalWrite(mot2,HIGH);
  digitalWrite(mot1,LOW);
   digitalWrite(mot3,HIGH);
  digitalWrite(mot4,LOW);
  delay(5000);
  //backward:
  digitalWrite(mot1,HIGH);
  digitalWrite(mot2,LOW);
   digitalWrite(mot4,HIGH);
  digitalWrite(mot3,LOW);
  delay(5000);
  //right:
  digitalWrite(mot4,HIGH);
  digitalWrite(mot3,LOW);
   digitalWrite(mot2,HIGH);
  digitalWrite(mot1,LOW);
  delay(5000);
  //left:
  digitalWrite(mot3,HIGH);
  digitalWrite(mot4,LOW);
   digitalWrite(mot1,HIGH);
  digitalWrite(mot2,LOW);
  delay(5000);
  
}
