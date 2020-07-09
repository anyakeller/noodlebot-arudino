const int togglePin1a = 2;
const int togglePin1b = 3;

int Toggle1State = 0; // -1, 0, 1
int currentToggle1aValue;
int currentToggle1bValue;

void setup() {
  pinMode(togglePin1a, INPUT);
  pinMode(togglePin1b, INPUT);
  Serial.begin(9600);
  Serial.println("========================================");
  Serial.println("Small toggle switch begin");
  Serial.print("Using ports: ");
  Serial.print(togglePin1a);
  Serial.print(" and ");
  Serial.println(togglePin1b);
  Serial.println("------------------");
   checkAndSetToggleValue();
}

void checkAndSetToggleValue(){
  currentToggle1aValue = digitalRead(togglePin1a);
  currentToggle1bValue = digitalRead(togglePin1b);
  
  if (currentToggle1aValue == HIGH) {
    Serial.print("Toggle 1 A: ");
    Serial.println(true);
  } else {
    Serial.print("Toggle 1 A: ");
    Serial.println(false );
  }
  if (currentToggle1bValue == HIGH) {
    Serial.print("Toggle 1 B: ");
    Serial.println(true);
  } else {
    Serial.print("Toggle 1 B: ");
    Serial.println(false );
  }
}

void loop() {
 
}
