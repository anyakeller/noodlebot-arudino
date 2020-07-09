// 2 axis analog center select joystick 
// Part: Digikey # 1568-1526-ND
// Directional ports: A0, A1

const int VERT = 0; // analog
const int HORIZ = 1; // analog

int vertical, horizontal, select;

void setup() {
  Serial.begin(9600);
  Serial.println("========================================");
  Serial.println("2 axis analog center select joystick switch begin");
  Serial.print("Using ANALOG ports: ");
  Serial.print(VERT);
  Serial.print(" and ");
  Serial.println(HORIZ);
  Serial.println("------------------");
}

void checkAndSetToggleValue(){
  
}

void loop() {
 
}
