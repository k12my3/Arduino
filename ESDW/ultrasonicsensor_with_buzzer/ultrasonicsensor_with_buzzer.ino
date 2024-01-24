const int trig = 12;
const int echo = 13;
const int LED1 = 8;
const int LED2 = 7;
const int LED3 = 6;
const int LED4 = 5;
const int LED5 = 4;
const int LED6 = 3;
const int LED 7 = 2;
int buzzer =9;
int duration = 0;
int distance = 0;
void setup() 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
  pinMode(LED6 , OUTPUT);
  pinMode(LED7 , OUTPUT);
  
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  
  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 29.1 ;
  Serial.println(distance);
  
  if ( distance <= 7 )          
  {
    digitalWrite(LED1, HIGH);
  tone(buzzer, 400);
  }
  else
  {
    digitalWrite(LED1, LOW);
  noTone(buzzer);
  }
  if ( distance <= 14 )
  {
    digitalWrite(LED2, HIGH);
  tone(buzzer, 400);
  }
  else
  {
    digitalWrite(LED2, LOW);
  noTone(buzzer);
  }
  if ( distance <= 21 )
  {
    digitalWrite(LED3, HIGH);
  tone(buzzer, 400);
  }
  else
  {
    digitalWrite(LED3, LOW);
  noTone(buzzer);
  }
  if ( distance <= 28 )
  {
    digitalWrite(LED4, HIGH);
  tone(buzzer, 400);
  }
  else
  {
    digitalWrite(LED4, LOW);
  noTone(buzzer);
  }
  if ( distance <= 35 )
  {
    digitalWrite(LED5, HIGH);
  tone(buzzer, 400);
  noTone(buzzer);
  }
  else
  {
    digitalWrite(LED5, LOW);
  }
  if ( distance <= 42 )
  {
    digitalWrite(LED6, HIGH);
  tone(buzzer, 400);
  }
  else
  {
    digitalWrite(LED6, LOW);
  noTone(buzzer);
  }
if ( distance <= 49 )
{
    digitalWrite(LED7, HIGH);
        tone(buzzer, 400);
}
else
{
    digitalWrite(LED7,LOW);
        noTone(buzzer);
}
}
