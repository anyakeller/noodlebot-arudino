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
  Serial.println("Using ANALOG ports: 0 and 1");
  Serial.println("------------------");

}

void loop() {

  vertical = analogRead(VERT); // will be 0-1023
  horizontal = analogRead(HORIZ); // will be 0-1023
  Serial.print("vertical: ");
  Serial.print(vertical, DEC);
  Serial.print(" horizontal: ");
  Serial.print(horizontal, DEC);
  Serial.println("Done");
}
