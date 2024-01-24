#define Relay 7
void setup()
{
  pinMode(Relay, OUTPUT);
}
void loop()
{
  digitalWrite(Relay,HIGH);
  delay(2000);
  digitalWrite(Relay,LOW);
  delay(1000);
  digitalWrite(Relay,HIGH);
  delay(5000);
}
