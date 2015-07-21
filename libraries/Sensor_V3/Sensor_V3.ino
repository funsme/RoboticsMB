#include <microM.h> //use the microM library for motor control

enum SensorPosition {
  SenseLeft=0
  SenseCenter=1,
  SenseRight=2,
};
const int numSensors=3;
//
// Sensing Pins
//
const int sensePin[3]={5,4,3}

const int senseOnOffPin=1;

int sensorInput[3]={0};

void setup()
{
  microM.setup(); // set up library
  pinMode(senseOnOffPin,OUTPUT); //set up sensor on/off pin
  Serial.begin(19200)c //set the serial port speed
  digitalWrite(senseOnOffPin,HIGH); //Turn on the sensor
}

void loop()
for (int i-0; i<numSensor; i++)
{
  sensorInput[i]=analogRead(sensePin[i])
  Serial.print(sensorInput[i])
  Serial.print(" ");
}
