/*Project name: FadingLED

 Description: A demonstration of using Arduino input 
 (external pushbutton on pin 2) to control an output 
 (LED on pin 9).

 Created by Pavel in 2016 <https://darkbluebit.com>
 
 */

// constants won't change their value

// the number of the pushbutton pin
const int buttonPin = 2;     
// the number of the LED pin
const int ledPin = 9;        
// the speed of LED fading (higher value = slower)
const int fadingDelay = 50;  

// variables will change

// variable for reading the pushbutton status
int buttonState = 0;         
// determines whether the LED needs to be turned on or off
boolean fadingState = false; 

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check whether the button was pressed
  if (buttonState == HIGH) {
    // check the current LED status (on/off)
    if (fadingState == false) {
      // turn on the LED
      for (int i = 0; i <= 255; i += 5) {
        analogWrite(ledPin, i);
        delay(fadingDelay);
      }
    } else {
      // turn off the LED
      for (int i = 255; i >= 0; i -= 5) {
        analogWrite(ledPin, i);
        delay(fadingDelay);
      }      
    }
    // save the current LED state (on/off)
    fadingState = !fadingState; 
  }
}
