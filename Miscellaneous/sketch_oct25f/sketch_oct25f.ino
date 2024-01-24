int ledpins[]={8,9,10,11,12,13};
void setup()
  {
    for (int i=0; i<6; i++)
      {
        pinMode(ledpins[i], OUTPUT);
      }
  }
void loop()
  {
    OneAfterAnotherNoLoop();
  }
void OneAfterAnotherNoLoop()
  {
    int delayTime=750;

    digitalWrite(ledpins[0], HIGH);
    delay(delayTime);
    digitalWrite(ledpins[1], HIGH);
    delay(delayTime);
    digitalWrite(ledpins[2], HIGH);
    delay(delayTime);
    digitalWrite(ledpins[3], HIGH);
    delay(delayTime);
    digitalWrite(ledpins[4], HIGH);
    delay(delayTime);
    digitalWrite(ledpins[5], HIGH);
    delay(delayTime);

    digitalWrite(ledpins[5], LOW);
    delay(delayTime);
    digitalWrite(ledpins[4], LOW);
    delay(delayTime);
    digitalWrite(ledpins[3], LOW);
    delay(delayTime);
    digitalWrite(ledpins[2], LOW);
    delay(delayTime);
    digitalWrite(ledpins[1], LOW);
    delay(delayTime);
    digitalWrite(ledpins[0], LOW);
    delay(delayTime);
  }
