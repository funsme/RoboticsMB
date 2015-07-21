/*
 This program demonstrates the use of the Micro Magician control board IR decoding function.
 This function decodes Sony IR Codes (SIRC) and returns the 7bit command as a byte. 
 
 Included in the library are instructions for configuring the universal remote sold by DAGU.
 
 Written by Russell Cameron
 */


#include <microM.h>


void setup()
{ 
  microM.Setup();                                // this must be called to initialize timer 2
  //microM.irpin=4;                              // only required for external IR receivers. Defaults to 4 for onboard IR receiver

  Serial.begin(9600);                            // initialize serial monitor
  Serial.println("Ready to receive IR commands");
}


void loop()
{
  static int leftDir=2,rightDir=2;
  if(microM.ircommand>0)                         // display command from IR receiver
  {
    Serial.print("\tIR command:");
    Serial.println(microM.ircommand,DEC);        // use the DEC option to convert a byte to a decimal number
    if(microM.ircommand == 117)
    {
      microM.Motors(2,2,1,1);

    }
    else if(microM.ircommand == 102)
    {
      microM.Motors(0,0,0,0);
    }
    else if(microM.ircommand == 53)
    {
      microM.Motors(0,2,0,1);
    }
    else if(microM.ircommand == 52)
    {

      microM.Motors(2,0,1,0);
    }
    else if(microM.ircommand == 118)
    {
      leftDir=-2,rightDir=-2;
      microM.Motors(2,2,1,1);
    }
    microM.ircommand=0;                          // prevents display repeating the same values
  } 
  
  
}


void MoveMotor()
{
  Serial.print("\tMove Motor function is called.");
  static int leftDir=2,rightDir=-2;                            // set rate of acceleration
  static int leftSpeed,rightSpeed;                             // motor control variables
  static byte leftBrake, rightBrake;

  leftSpeed+=leftDir;                                          // accelerate/deccelerate motor
  if(leftSpeed<-254 || leftSpeed>254) 
  {
    leftDir=-leftDir;                                          // if peak speed reached then reverse direction
    leftBrake=1;                                               // if peak speed reached then brake motor
  }
  if(leftSpeed==0) leftBrake=0;                                // release brake when motor speed = 0
  
  rightSpeed+=rightDir;                                        // accelerate/deccelerate motor
  if(rightSpeed<-254 || rightSpeed>254)                        
  {
    rightDir=-rightDir;                                        // if peak speed reached then reverse direction
    rightBrake=1;                                              // if peak speed reached then brake motor
  }
  if(rightSpeed==0) rightBrake=0;                              // release brake when motor speed = 0
  
  delay(10);                                                
  microM.Motors(leftSpeed,rightSpeed,leftBrake,rightBrake);    // update motor controller
}

/*
=================================================== Available Global Variables =====================================================
 
 microM.irpin
 A byte value specifying the digital pin used by IR receiver (default value is 4).
 Only required if using an external IR receiver.
 
 */








