#define relay 7
int sensor =8;
int mot1 =12;
int mot2 =11;
int mot3 =10;
int mot4 =9;
void setup()
{
  pinMode(relay, OUTPUT);
  pinMode(sensor,INPUT);
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);
}
void loop()
{
  int data = digitalRead(sensor);
  if(data == LOW)
  {
   digitalWrite(relay, LOW);
   digitalWrite(mot2,HIGH);
   digitalWrite(mot1,LOW);
   digitalWrite(mot3,HIGH);
   digitalWrite(mot4,LOW);
  }
  else
  {
   digitalWrite(relay,HIGH);
   digitalWrite(mot1,HIGH);
   digitalWrite(mot2,LOW);
   digitalWrite(mot4,HIGH);
   digitalWrite(mot3,LOW);
   delay(5000);

  }
}
