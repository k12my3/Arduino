#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8, 9); // CE, CSN
const byte address[6] = "00001";

const char text[] = "test 123";

void setup() 
{
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(9600);
  encode();
}

void loop() 
{
  radio.write(&text, sizeof(text));
  delay(1000);
}

void encode()
{
  /*for(int i=0; i <=length(text); i++)
  {
    Serial.print(text[i] + " ");
  }
  Serial.println("\n");*/

  Serial.println(text, HEX)
}
