
#include <SoftwareSerial.h>
SoftwareSerial esp8266(3,2); //rx, tx

#define DEBUG true
#define SSID "Airtel_264" // x -> wifi network name
#define PASS "Kabhi428" // x -> wifi network password

int state = 5;



String sendAT(String command, const int timeout,  boolean debug) //send AT commands to esp8266
{
  String response = ""; //response / sub with 'res'
  esp8266.print(command);
  long int time = millis();
  while((time + timeout) > millis())
  {
    while(esp8266.available())
    {
      char c = esp8266.read();
      response += c;
    }
  }

  if(debug) //DEBUG (?)
  {
    Serial.print(response);
  }
  return response;
}

void setup() //initialise communication b/w arduino & esp8266
{
  Serial.begin(9600);
  esp8266.begin(9600);

  sendAT("AT+RST\r\n", 2000, DEBUG); //reset AT
  sendAT("AT+CWMODE=1\r\n", 1000, DEBUG); //station mode
  sendAT("AT+CWJAP=\""SSID"\",\""PASS"\"\r\n", 2000, DEBUG); //connect to wifi
  while(!esp8266.find("OK")) 
  {
    //wait for connection
  }
  sendAT("AT+CIFSR\r\n", 1000, DEBUG); //print IP addr
    sendAT("AT+CIPSTA=\"192.168.1.107\",\"192.168.1.1\",\"255.255.255.0\"\r\n", 3000, DEBUG); // Assign Static IP Address
    sendAT("AT+CIFSR\r\n", 1000, DEBUG);//You will get the IP Address of the ESP8266 from this command. 
  sendAT("AT+CIPMUX=1\r\n", 1000, DEBUG);
  sendAT("AT+CIPSERVER=1,80\r\n", 1000, DEBUG);
  delay(4000);
  digitalWrite(13, HIGH);
  Serial.println("Initialization complete");

  //motor pins:
  pinMode(10, OUTPUT); //R+
  pinMode(11, OUTPUT); //R-
  pinMode(12, OUTPUT); //L+
  pinMode(13, OUTPUT); //L-
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() //read data from esp8266
{
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  if(esp8266.available())
  {
    if(esp8266.find("+IPD,")) //if msg contains +IPD
    {
      String msg;
      esp8266.find("?"); //look for > ? < in message
      msg = esp8266.readStringUntil(' '); //read the whole msg 
      String command = msg.substring(0,3); //first 3 chars -> cmd
      String valueStr = msg.substring(4); //next 4 chars -> value
      int value = valueStr.toInt(); // conv string to int
      if(DEBUG)
      {
        Serial.println(command);
        Serial.println(value);
      }

      if(command=="cm1")
      {
        state=1;
        Serial.println("Forward");
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
      }
      if(command=="cm2")
      {
        state=2;
        Serial.println("Backward");
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
      }
      if(command=="cm3")
      {
        state=3;
        Serial.println("Left");
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, HIGH);
      }
      if(command=="cm4")
      {
        state=4;
        Serial.println("Right");
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
      }
      if(command=="cm5")
      {
        state=5;
        Serial.println("Stop");
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
      }
      if(command=="cm6") //test connection b/w HTML client & bot
      {
        state=6;
        Serial.println("Connected to client");
        Serial.println("Control the robot w/ arrow keys");
      }
    }
  }
}