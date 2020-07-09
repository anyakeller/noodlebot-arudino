const int togglePin1 = A1;
const int togglePin2 = A2;

bool Toggle1State = true;
bool Toggle2State = true;
int currentToggle1Value;
int currentToggle2Value;


void setup() {
  pinMode(togglePin1,INPUT);
  pinMode(togglePin2,INPUT);
  currentToggle1Value = digitalRead(togglePin1);
  currentToggle2Value = digitalRead(togglePin2);
  if (currentToggle1Value == 0){
    Toggle1State = false;
  }
  if (currentToggle2Value == 0){
    Toggle2State = false;
  }
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Toggle switch YEEET");
  Serial.print("Toggle 1 status is now: ");
  Serial.println(Toggle1State);
  Serial.print("Toggle 2 status is now: ");
  Serial.println(Toggle2State);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentToggle1Value = digitalRead(togglePin1);
  currentToggle2Value = digitalRead(togglePin2);

  if (currentToggle1Value > 0 && !Toggle1State){
    Toggle1State = true;
    Serial.print("Toggle 1 status is now: ");
    Serial.println(Toggle1State);
    Serial.println(currentToggle1Value);
  } else if (currentToggle1Value <1 && Toggle1State){
    Toggle1State = false;
    Serial.print("Toggle 1 status is now: ");
    Serial.println(Toggle1State);
    Serial.println(currentToggle1Value);
  }
  if (currentToggle2Value > 0 && !Toggle2State){
    Toggle2State = true;
    Serial.print("Toggle 2 status is now: ");
    Serial.println(Toggle2State);
    Serial.println(currentToggle2Value);
  } else if (currentToggle2Value < 1 &&Toggle2State){
    Toggle2State = false;
    Serial.print("Toggle 2 status is now: ");
    Serial.println(Toggle2State);
    Serial.println(currentToggle2Value);
  }
  
}
