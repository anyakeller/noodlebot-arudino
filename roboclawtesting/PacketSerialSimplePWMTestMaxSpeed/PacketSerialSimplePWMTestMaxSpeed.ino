//See BareMinimum example for a list of library functions

//Includes required to use Roboclaw library
#include <SoftwareSerial.h>
#include "RoboClaw.h"

//See limitations of Arduino SoftwareSerial
SoftwareSerial serial(10, 11);
RoboClaw roboclaw(&serial, 10000);

#define address 0x80

void setup() {
  Serial.begin(57600);
  //Open roboclaw serial ports
  roboclaw.begin(38400);
}

void loop() {
  roboclaw.ForwardM1(address,  127); //start Motor1 forward at half speed
  roboclaw.ForwardM2(address,  127); //start Motor2 backward at half speed
  delay(2000);
  int32_t speed1 = roboclaw.ReadSpeedM1(address); //18
  int32_t speed2 = roboclaw.ReadSpeedM2(address); //19
  Serial.print("M1 speed: ");
  Serial.print(speed1);
  Serial.print(" ");
  Serial.print("M2 speed: ");
  Serial.print(speed2);
  Serial.println();
}
