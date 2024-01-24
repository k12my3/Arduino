const int pingPin =8; //Trigger pin of ultrasonic sensor
const int echoPin=10; //Echo pin of ultrasonic sensor
int led =A0;
void setup()
{
  pinMode (led, OUTPUT);
  Serial.begin(9600); // Startingserial Terminal
}
void loop()
{
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin,HIGH);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin,HIGH);

  cm = duration/29/2;

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(1000);

  if(cm<30)
  {
    digitalWrite(led, HIGH);
    Serial.println("led glowing");
    lcd.printIn(cm);
  }
  else
  {
    digitalWrite(led, LOW);
    lcd.print("Greater");
    lcd.setcursor(1,1);
    lcd.print("than 30cm");
  }
}
// return microseconds /29/2
