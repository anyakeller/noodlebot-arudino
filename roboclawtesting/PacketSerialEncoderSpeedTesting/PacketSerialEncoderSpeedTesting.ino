//See BareMinimum example for a list of library functions
// 48 8 gear ratio
// 48 * 4.4 = 211.2

//Includes required to use Roboclaw library
#include <SoftwareSerial.h>
#include "RoboClaw.h"

//See limitations of Arduino SoftwareSerial
SoftwareSerial serial(10, 11);
RoboClaw roboclaw(&serial, 10000);

#define address 0x80

//M1 Velocity PID coefficients.
#define Kp 1
#define Ki 0
#define Kd 0
#define qpps 10203

//M2 Velocity PID coefficients.
#define M2Kp 1
#define M2Ki 0
#define M2Kd 0
#define M2qpps 10130

void setup() {
  //Open Serial and roboclaw serial ports
  Serial.begin(57600);
  roboclaw.begin(38400);

  //Set PID Coefficients
  roboclaw.SetM1VelocityPID(address, Kd, Kp, Ki, qpps);
  roboclaw.SetM2VelocityPID(address, Kd, Kp, Ki, qpps);

  Serial.println("Roboclaw packet serial encoder speed testing ====================");

}


void displayspeed(void)
{
  uint8_t status1, status2, status3, status4;
  bool valid1, valid2, valid3, valid4;

  int32_t enc1 = roboclaw.ReadEncM1(address, &status1, &valid1);
  int32_t enc2 = roboclaw.ReadEncM2(address, &status2, &valid2);
  int32_t speed1 = roboclaw.ReadSpeedM1(address, &status3, &valid3); //18
  int32_t speed2 = roboclaw.ReadSpeedM2(address, &status4, &valid4); //19

  if (valid1 && valid2 && valid3 && valid4) {
    Serial.print("Encoder1:");
    if (valid1) {
      Serial.print(enc1, HEX);
      Serial.print(" ");
      Serial.print(status1, HEX);
      Serial.print(" ");
    }
    else {
      Serial.print("invalid ");
    }
    Serial.print("Encoder2:");
    if (valid2) {
      Serial.print(enc2, HEX);
      Serial.print(" ");
      Serial.print(status2, HEX);
      Serial.print(" ");
    }
    else {
      Serial.print("invalid ");
    }
    Serial.print("Speed1:");
    if (valid3) {
      //Serial.print(speed1, HEX);
      Serial.print(speed1);
      Serial.print(" ");
    }
    else {
      Serial.print("invalid ");
    }
    Serial.print("Speed2:");
    if (valid4) {
      // Serial.print(speed2, HEX);
      Serial.print(speed2);
      Serial.print(" ");
    }
    else {
      Serial.print("invalid ");
    }
    Serial.print("Main battery voltage: ");
    Serial.print(roboclaw.ReadMainBatteryVoltage(address));
    Serial.println();
  }
}

void loop() {
  /*
    roboclaw.SpeedM1(address,8000);
    for(uint8_t i = 0;i<100;i++){
    displayspeed();
    delay(10);
    }

    roboclaw.SpeedM1(address,-8000);
    for(uint8_t i = 0;i<100;i++){
    displayspeed();
    delay(10);
    }
  */
  // roboclaw.SpeedM1(address, 4500); //35 and 36
  roboclaw.SpeedAccelM1(address, 2000, 1760); 
  roboclaw.SpeedAccelM2(address, 2000, 1760);
  // roboclaw.SpeedAccelM1 ( acceleration (velocity/s), velocity (pulses/s) )
  // 400 rpm => 1760 pulses/s on 4.4:1
  for (uint8_t i = 0; i < 100; i++) {
    displayspeed();
    delay(500);
  }
}
