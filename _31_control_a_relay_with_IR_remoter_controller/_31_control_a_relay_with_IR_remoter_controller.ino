/***********************************************************
File name: 31_control_a_relay_with_IR_remoter_controller.ino
Description: When you press the 0 and 1 keys on the remote 
             control, you will hear the sound of the relay.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/
#include <IRremote.h>
int RECV_PIN = 5;//The definition of the infrared receiver pin 5
const int relayPin = 8; //the base of the transistor attach to
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
   pinMode(relayPin, OUTPUT); //initialize the relayPin as an output
   irrecv.enableIRIn(); // Initialization infrared receiver
} 

void loop() 
{
  if (irrecv.decode(&results)) { 
    if(results.value==0xC101E57B)//0
    {   
       digitalWrite(relayPin, LOW); //drive the relay is closed off
    }
    if(results.value==0x9716BE3F)//1
    {
      digitalWrite(relayPin, HIGH); //drive relay closure conduction 
    }
    irrecv.resume(); // Receiving the next value
  }  
}
   

