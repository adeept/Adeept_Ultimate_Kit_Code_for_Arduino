/***********************************************************
File name:   36_button_Processing.ino
Description: Arduino and processing interactive
             Button controls Snake Game
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/
int btnLPin = 2;//Define digital 2 pin connect the left button
int btnRPin = 3;//Define digital 3 pin connect the left button

int Lval = 0;
int Rval = 0;

void setup() { 
  // Start the serial port, baud rate to 9600
  Serial.begin(9600); 
  pinMode(btnLPin,INPUT_PULLUP);//Set btnLPin input and pull up module
  pinMode(btnRPin,INPUT_PULLUP);//Set btnRPin input and pull up module
} 
  
void loop() { 
  // Read the button information
  int Lval = digitalRead(btnLPin);
  int Rval = digitalRead(btnRPin);
  
  Serial.print(Lval);//Send Lval
  Serial.print(',');
  Serial.print(Rval);//Send Rval
  Serial.println(','); 
  delay(100);         //Delay 100ms
} 

