#include <DualMAX14870MotorShield.h>

#define LED_PIN 13
const int toggleADir1 = A2;
const int toggleADir2 = A3;
const int toggleBDir1 = A4;
const int toggleBDir2 = A5;

int togglePins[] = {A2,A3,A4,A5};

bool toggleStates[] = {false,false,false,false};
int currentToggleValues[] = {0,0,0,0};

DualMAX14870MotorShield motors(7,9,8,10,4,12);

void stopIfFaulMt()
{
  if (motors.getFault())
  {
    while (1)
    {
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
      delay(100);
    }
  }
}

void checkAndSet(int whichOne){
  int currentValue = analogRead(togglePins[whichOne]);
  currentToggleValues[whichOne] = currentValue;
  if (currentValue > 900){
    if (!toggleStates[whichOne]){
      Serial.print("Toggle ");
      Serial.print(togglePins[whichOne]);
      Serial.print(" is now: ");
      Serial.println(true);
      
      if (whichOne == 0){
        runM1(150);
      } else if(whichOne == 1){
        runM1(-150);
      }else if(whichOne == 2){
        runM2(150);
      }else if(whichOne == 3){
        runM2(-150);
      }
    }
    toggleStates[whichOne] = true;
  } else {
    if (toggleStates[whichOne]){
      Serial.print("Toggle ");
      Serial.print(togglePins[whichOne]);
      Serial.print("is now: ");
      Serial.println(false);
    }
    toggleStates[whichOne] = false;
  }
}

void setup(){
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Dual Motor YEEET");
  // uncomment one or both of the following lines if your motors' directions
  // need to be flipped
  //motors.flipM1(true);
  //motors.flipM2(true);
  motors.enableDrivers();
  motors.flipM1(true);
  Serial.println("Toggle switch YEEET");
  Serial.println("Using ports 7,9,8,10,4,12");
  checkAndSet(0);
  checkAndSet(1);
  checkAndSet(2);
  checkAndSet(3);
}


void runM1(int speedDirection){
  motors.setM1Speed(speedDirection);
  stopIfFaulMt();
}
void stopM1(){
  motors.setM1Speed(0);
  stopIfFaulMt();
}

void runM2(int speedDirection){
  motors.setM2Speed(speedDirection);
  stopIfFaulMt();
}
void stopM2(){
  motors.setM2Speed(0);
  stopIfFaulMt();
}


void loop(){
  
  checkAndSet(0);
  checkAndSet(1);
  checkAndSet(2);
  checkAndSet(3);

  if (!toggleStates[0] && !toggleStates[1]) {
    stopM1();
  }
  if (!toggleStates[2] && !toggleStates[3]) {
    stopM2();
  }
  //delay(1);
  /*
  currentButtonState = digitalRead(buttonPin);
  if (prevButtonState != currentButtonState){
    Serial.print("Prev btn state: ");
    Serial.println(prevButtonState);
    Serial.print("Current btn state: ");
    Serial.println(currentButtonState);    
    prevButtonState = currentButtonState;
    if (currentButtonState == 0){
      // run M1 motor with positive speed
      Serial.println("M1");
      digitalWrite(LED_PIN, HIGH);
      motors.setM2Speed(0);
      motors.setM1Speed(400);
      stopIfFault();
    } else{
      Serial.println("M2");
      digitalWrite(LED_PIN, HIGH);
      motors.setM1Speed(0);
      motors.setM2Speed(400);
      stopIfFault();
    }
  }
  */
  //motors.disableDrivers();
}
