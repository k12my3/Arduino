#include <WiFi.h>
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros

const char* ssid = "KLH EPA2";   // your network SSID (name) 
const char* password = "";   // your network password

WiFiClient  client;
unsigned long myChannelNumber = 1651570;
const char * myWriteAPIKey = "FA4N7NC8HA9P2LNP";

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 30000;

void setup() 
{
  Serial.begin(115200);  //Initialize serial 
  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() 
{
  if ((millis() - lastTime) > timerDelay) 
  {  
    // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED)
    {
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED)
      {
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }

    //new readings
    int pb = digitalRead(23);
    long rssi = WiFi.RSSI();
    Serial.print ("PB Status : ");
    Serial.println (pb);
    Serial.print ( "WiFi Strength : " ) ;
    Serial.println (rssi);
    delay(5000) ;
    
    ThingSpeak.setField(1, pb);
    ThingSpeak.setField(2, str);
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

    Serial.println((x==200) ? ("Channel update successful") : ("Problem updating channel. HTTP error code " + String(x)));
    lastTime = millis();
  }
}
