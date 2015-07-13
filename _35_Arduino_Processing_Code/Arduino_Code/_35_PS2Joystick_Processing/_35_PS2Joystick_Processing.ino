/***********************************************************
File name:   35_PS2Joystick_Processing.ino
Description: Arduino and processing interactive
             The Joystiak data which Arduino collected send 
             the processing software to display.  
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/
int xpotPin = 0; // Define UNO board A0 pin connect the Ioystick x
int ypotPin = 1; // Define UNO board A1 pin connect the Ioystick y
int swPin = 9;   // Define UNO board digital 9 pin connect the Ioystick sw

int xval = 0;
int yval = 0;
int swval= 0;

void setup() { 
  // Start the serial port, baud rate to 9600
  Serial.begin(9600); 
  pinMode(swPin,INPUT_PULLUP);//Set swPin inputand pull up 
} 
  
void loop() { 
  // Read the Joystick x y sw information
  int xval = analogRead(xpotPin);
  int yval = analogRead(ypotPin);
  int swval = digitalRead(swPin);
  
  Serial.print(xval);//Dend xval value
  Serial.print(',');
  Serial.print(yval);//Dend yval value
  Serial.print(',');
  Serial.print(swval);//Dend swval value
  Serial.println(','); 
  delay(100); 
} 

