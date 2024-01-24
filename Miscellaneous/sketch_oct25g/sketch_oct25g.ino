int ledpins[]={8,9,10,11,12,13};
int i=0;
int delayTime=1000;
void setup()
{  
  pinMode(ledpins[i], OUTPUT);
}
 void loop()

{
  for (int i=0; i<=5; i++)
         
  {
    digitalWrite(ledpins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledpins[i], LOW);
    delay(delayTime);
  }

 for (int i=5; i>=0; i--)
        
  {
    digitalWrite(ledpins[i], LOW);
    delay(delayTime);
    digitalWrite(ledpins[i], HIGH);
    delay(delayTime);
  }
}
