
// Ultrasonic sensor : Trig - p.6, Echo - p.7 || IR Sensor - p.5 || LCD Data Pins - (8-11)

#include <LiquidCrystal.h>

const int trig = 6;
const int echo = 7;
const int ir = 5;
int buzzer = 2;

int duration = 0;
int distance = 0;

LiquidCrystal lcd(3,4,8,9,10,11);
void setup() 
{
  pinMode(ir, INPUT);
  pinMode(echo , INPUT);
  pinMode(trig , OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16,2);
}

void ring()
{
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
}

void nomotion()
{
 digitalWrite(buzzer, LOW);
 lcd.setCursor(0,0);
 lcd.print("No Body Detected");
 lcd.setCursor(0,1);
 lcd.print("Please try again.");
 delay(1000);
}

void loop() 
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  
  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 29.1 ;

  if(distance<=10)
  {
    lcd.setCursor(0,0);
    lcd.print("Detecting Body  "); //Ultrasonic detects an object within 10cms
    lcd.setCursor(0,1);
    lcd.print("Sensor Activated");
    delay(2000);

    if(digitalRead(ir)==0)      //IR Sensor is activated for first time
    {
      lcd.setCursor(0,0);
      lcd.print("Trial Succesful");
      lcd.setCursor(0,1);
      lcd.print("Raise hand in 3s");
      delay(2000);

      if(digitalRead(ir)==0)    //IR Sensor is activated for the second time (consecutively)
      {
        lcd.setCursor(0,0);
        lcd.print("Motion Detected");
        lcd.setCursor(0,1);
        lcd.print("Ringing Doorbell");        
        ring();
        delay(2000);
      }
      else
      {
        nomotion();
      }
    }
    else
    {
      nomotion();
    }
  }
  else
  {
    nomotion();
  }
  delay(2000);
}
