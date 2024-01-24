#define relay 7
int sensor =8;
void setup()
{
  pinMode(relay, OUTPUT);
  pinMode(sensor,INPUT);
}
void loop()
{
  int data = digitalRead(sensor);
  if(data == LOW)
  {
    digitalWrite(relay, LOW);
  }
  else
  {
        digitalWrite(relay,HIGH);

  }
}
