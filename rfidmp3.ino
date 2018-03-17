#include <deprecated.h>
#include <require_cpp11.h>
#include <MFRC522Extended.h>
#include <MFRC522.h>

// digital pin 2 has a pushbutton attached to it. Give it a name:
int yButton = 2;
int buttonState = 0;

#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN,RST_PIN);

void setup(){
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(yButton, INPUT_PULLUP);
  rfid.init();
  
}
void loop(){
  // read the input pin:
  int buttonState = digitalRead(yButton);
  // print out the state of the button:
  // Serial.println(buttonState);  //If button pressed...
  if rfid.isCard(){
    Serial.print('Card #')
    Serial.print(rfid.readCardSerial())
    Serial.println()
  }
  else{
    Serial.println('no card')
  }

  delay(200);        // delay in between reads for stability
}
