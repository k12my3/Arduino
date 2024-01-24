
#include <SoftwareSerial.h>
SoftwareSerial MyBlue(2,3); //Tx, Rx

char c = ' ';
void setup () 
{
  Serial.begin (9600) ;
  MyBlue.begin (38400) ;
  Serial.println (" *** AT commands mode *** ");
}

void loop () 
{
  if (MyBlue.available())
  Serial.write (MyBlue.read());
  // from termial to bluetooth
  if (Serial.available()) 
  {
    c=Serial.read() ;
    Serial.write(c);
    MyBlue.write(c);
 }
}
