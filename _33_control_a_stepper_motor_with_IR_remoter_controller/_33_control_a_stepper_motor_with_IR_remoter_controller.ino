/***********************************************************
File name: 33_control_a_stepper_motor_with_IR_remoter_controller.ino
Description: when you press the ‘0’ to ‘9’ buttons on the
             remote control, you will see the stepper motor 
             to rotate. When you press the '+' and '-' buttons
             on the remote control, you can control the stepper
             motor to be forward or reverse.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/05/02 
***********************************************************/
#include <IRremote.h>
int RECV_PIN = 5;//The definition of the infrared receiver pin 5
int Pin0 = 8;//definition digital 8 pins as pin to control the IN1 (ULN24L01)
int Pin1 = 9;//definition digital 9 pins as pin to control the IN2 (ULN24L01)
int Pin2 = 10;//definition digital 10 pins as pin to control the IN3 (ULN24L01)
int Pin3 = 11;//definition digital 11 pins as pin to control the IN4 (ULN24L01)

int _step = 512; 
int _speed = 1; 
IRrecv irrecv(RECV_PIN);
decode_results results;
int dir;
void setup()
{
   pinMode(Pin0, OUTPUT);//Set digital 8 port mode, the OUTPUT for the output
   pinMode(Pin1, OUTPUT);//Set digital 9 port mode, the OUTPUT for the output
   pinMode(Pin2, OUTPUT);//Set digital 10 port mode, the OUTPUT for the output
   pinMode(Pin3, OUTPUT);//Set digital 11 port mode, the OUTPUT for the output
   irrecv.enableIRIn(); //Initialization infrared receiver
} 

void loop() 
{
  if (irrecv.decode(&results)) { 
    switch(results.value){
    case 0xF076C13B/*-*/:
                        dir = 1;
                        break;
    case 0xA3C8EDDB/*+*/:
                        dir = 0;
                        break;
    case 0xC101E57B/*0*/: 
                        Speed(15); //Stepper motor speed = 1 slow  (note:speed from 1 to 15)
                        Step(0);   //Stepper motor stop   
                        break;
    case 0x9716BE3F/*1*/:
                        Speed(15);//Stepper motor speed = 15 fast (note:speed from 1 to 15)
                        if(dir==0){
                          Step(512);//Stepper motor forward 512 steps ---- 360 angle  
                        }else{
                          Step(-512);//Stepper motor backward 512 steps ---- 360 angle
                        }                       
                        break;
    case 0x3D9AE3F7/*2*/: 
                        Speed(15);//Stepper motor speed = 15 fast (note:speed from 1 to 15)
                        if(dir==0){
                          Step(1024);//Stepper motor forward 1024 steps ---- 2*360 angle 
                        }else{
                          Step(-1024);//Stepper motor backward 1024 steps ---- 2*360 angle
                        }
                        break;
    case 0x6182021B/*3*/:
                        Speed(15);//Stepper motor speed = 15 fast (note:speed from 1 to 15)
                        if(dir==0){
                          Step(1536);//Stepper motor forward 1536 steps ---- 3*360 angle
                        }else{
                          Step(-1536);//Stepper motor backward 1536 steps ---- 3*360 angle 
                        }
                        break;
    case 0x8C22657B/*4*/:  
                        Speed(15);//Stepper motor speed = 15 fast (note:speed from 1 to 15)
                        if(dir==0){
                          Step(2048);//Stepper motor forward 2048 steps ---- 4*360 angle
                        }else{
                          Step(-2048);//Stepper motor backward 2048 steps ---- 4*360 angle
                        }
                        break;
    case 0x488F3CBB/*5*/: 
                        Speed(15);//Stepper motor speed = 15 fast (note:speed from 1 to 15)
                        if(dir==0){
                          Step(2560);//Stepper motor forward 2560 steps ---- 5*360 angle
                        }else{
                          Step(-2560);//Stepper motor backward 2560 steps ---- 5*360 angle
                        }
                        break;
    case 0x449E79F/*6*/: 
                        Speed(15);//Stepper motor speed = 15 fast (note:speed from 1 to 15)
                        if(dir==0){
                          Step(3072);//Stepper motor forward 3072 steps ---- 6*360 angle 
                        }else{
                          Step(-3072);//Stepper motor backward 3072 steps ---- 6*360 angle
                        }
                        break;
    case 0x32C6FDF7/*7*/:  
                        Speed(15);//Stepper motor speed = 15 fast (note:speed from 1 to 15)
                        if(dir==0){                      
                          Step(3584);//Stepper motor forward 3584 steps ---- 7*360 angle 
                        }else{
                          Step(-3584);//Stepper motor backward 3584 steps ---- 7*360 angle 
                        }
                        break;
    case 0x1BC0157B/*8*/: 
                        Speed(15);//Stepper motor speed = 15 fast (note:speed from 1 to 15)
                        if(dir){
                        Step(4096);//Stepper motor forward 4096 steps ---- 8*360 angle
                        }else{
                        Step(-4096);//Stepper motor backward 4096 steps ---- 8*360 angle
                        }
                        break;
    case 0x3EC3FC1B/*9*/: 
                        Speed(15);//Stepper motor speed = 15 fast (note:speed from 1 to 15)
                        if(dir==0){
                        Step(4608);//Stepper motor forward 4608 steps ---- 9*360 angle  
                        }else{
                        Step(-4608);//Stepper motor backward 4608 steps ---- 9*360 angle 
                        }
                        break;
    default :
             Step(0);   //Stepper motor stop
             break;
    }        
    irrecv.resume(); // Receiving the next value
  }  
}
void Speed(int stepperspeed)//set Stepper speed 
{
    _speed = 15 - stepperspeed;
    if( _speed<1){
     _speed = 1;
    }
    if( _speed>15){
     _speed = 15;
    }
}
void Step(int _step)//Stepper motor rotation
{
  if(_step>=0){  // Stepper motor forward
    for(int i=0;i<_step;i++){   
      setStep(1, 0, 0, 1);
      delay(_speed); 
      setStep(1, 0, 0, 0);
      delay(_speed);
      setStep(1, 1, 0, 0);
      delay(_speed);
      setStep(0, 1, 0, 0);
      delay(_speed);
      setStep(0, 1, 1, 0);
      delay(_speed);
      setStep(0, 0, 1, 0);
      delay(_speed);
      setStep(0, 0, 1, 1);
      delay(_speed); 
      setStep(0, 0, 0, 1);
      delay(_speed);
    }
  }else{ // Stepper motor backward
     for(int i=_step;i<0;i++){  
      setStep(0, 0, 0, 1);
      delay(_speed);
      setStep(0, 0, 1, 1);
      delay(_speed);
      setStep(0, 0, 1, 0);
      delay(_speed);
      setStep(0, 1, 1, 0);
      delay(_speed);
      setStep(0, 1, 0, 0);
      delay(_speed);
      setStep(1, 1, 0, 0);
      delay(_speed);
      setStep(1, 0, 0, 0);
      delay(_speed);
      setStep(1, 0, 0, 1);
      delay(_speed);
    }
   }
}
void setStep(int a, int b, int c, int d)  
{  
    digitalWrite(Pin0, a);     
    digitalWrite(Pin1, b);     
    digitalWrite(Pin2, c);     
    digitalWrite(Pin3, d);     
}     

