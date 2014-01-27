/*
 DIGF 2B03
 Connor Campbell - 2389765
 LAB 2
 Button used to alternate between 3 different LEDs 
 Base codes: 
 Button example, by DojoDave <http://www.0j0.org> (modified 30 Aug 2011 by Tom Igoe)
 http://www.arduino.cc/en/Tutorial/Button
 Button State Change example by Tom Igoe
 http://arduino.cc/en/Tutorial/ButtonStateChange
 Blink example
 http://arduino.cc/en/Tutorial/Blink
 */

int led1 = 13; 
int led2 = 12; 
int led3 = 11; 

int button = 2;   
int buttonState = 0;     
int lastbuttonState = 0;
int buttonPushCounter = 0;

void setup() {
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);  
  pinMode(button, INPUT);   

}

void loop(){

  buttonState = digitalRead(button);  
  if (buttonState != lastbuttonState) {        
    if (buttonState == HIGH) {
      buttonPushCounter++; 
    }
  }

  lastbuttonState = digitalRead(button);

  if (buttonPushCounter >= 3) {
    buttonPushCounter = 0;
  }

  if (buttonPushCounter == 0) {
    
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  else if (buttonPushCounter == 1) {

    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led3, LOW);
  }

  else if (buttonPushCounter == 2) {

    digitalWrite(led3, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

}
