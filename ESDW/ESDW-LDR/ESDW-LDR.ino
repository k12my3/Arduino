
// LDR Circuit

int ledPin=13;
int ldrPin=A0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(ldrPin,INPUT);
}

void loop()
{
  int ldrStatus = analogRead(ldrPin);
  if(ldrStatus <=10)
  {
    digitalWrite(ledPin,HIGH);
    Serial.println(ldrStatus);
    delay(1000);
  }
  else
  {
    digitalWrite(ledPin,LOW);
    Serial.println(ldrStatus);
    delay(1000);
  }
}
