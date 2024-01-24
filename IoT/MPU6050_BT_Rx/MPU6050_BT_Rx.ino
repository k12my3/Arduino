
#include <SoftwareSerial.h>
SoftwareSerial BTSerial (2 , 3) ; // RX | TX
char c = ' ';

void setup() 
{
  pinMode(8, OUTPUT); //R+
  pinMode(9, OUTPUT); //R-
  pinMode(10, OUTPUT); //L+
  pinMode(11, OUTPUT); //L-
  
  Serial . begin (9600) ;
  Serial . println (" Arduino with HC -05 is ready to recieve ");

  BTSerial . begin (38400) ;
  Serial . print (" BTserial started at 38400 ");
  pinMode ( LED_BUILTIN , OUTPUT ) ; //pin 13
}

void moveRobot(String motion)
{
  if(motion=="Forward")
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  if(motion=="Left")
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  if(motion=="Right")
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  if(motion=="Backward")
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  if(motion=="stop")
  {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}

void loop ()
{
  // Keep reading from HC -06 and send to Arduino Serial Monitor
  if (BTSerial . available ())
  {
    c = BTSerial.read () ;
    Serial.println (c );
    switch ( c)
    {
      case 'F':
      moveRobot("Forward"); break;
      case 'B':
      moveRobot("Backward"); break; 
      case 'L':
      moveRobot("Left"); break;
      case 'R':
      moveRobot("Right"); break;
      case 'S':
      moveRobot("stop"); break;
      default :
      moveRobot("stop");
    }
  }
}
