const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 9;
const int ENB = 3;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Yeet setup");
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//control speed 
  //analogWrite(ENA, 255);
 // analogWrite(ENB, 255); 
//control direction 
  Serial.println("Motor 1");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  Serial.println("Motor 2");
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
