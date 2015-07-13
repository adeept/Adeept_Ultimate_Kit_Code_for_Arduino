/***********************************************************
File name:   37_Button_PS2Joystick_Processing.ino
Description: Arduino and processing interactive
             Button and Joystick control Star Wars game
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/
int xpotPin = 0; // Define UNO board A0 pin connect the Ioystick x
int ypotPin = 1; // Define UNO board A1 pin connect the Ioystick y
int btnPin = 9;  // Define UNO board digital 9 pin connect the button

int xval = 0;
int yval = 0;
int btnval= 0;

void setup() { 
  // Start the serial port, baud rate to 9600
  Serial.begin(9600); 
  pinMode(btnPin,INPUT_PULLUP);//Set btnPin inputand pull up 
} 
  
void loop() { 
  // Read the Joystick x y and button information
  int xval = analogRead(xpotPin);
  int yval = analogRead(ypotPin);
  int btnval = digitalRead(btnPin);
  
  Serial.print(xval);//Dend xval value
  Serial.print(',');
  Serial.print(yval);//Dend yval value
  Serial.print(',');
  Serial.print(btnval);//Dend btnval value
  Serial.println(','); 
  delay(100); 
} 

