int sensorThreshold=200;
int buzzer=8;
int smokeA0 = A0;

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int mqvalue = analogRead(smokeA0);
  Serial.print("\n MQ2 Value : ");
  Serial.print(mqvalue);

  if(mqvalue > sensorThreshold)
  {
    Serial.print("\n Smoke Detected");
    tone(buzzer, 1000);
  }
  else
  {
    Serial.println("\nNo Smoke Detected");
    noTone(buzzer);
  }
  delay(500);
}
