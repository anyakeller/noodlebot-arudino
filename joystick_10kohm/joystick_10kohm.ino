// 2 axis analog 10k ohm joystick
// Part: Digikey # 1528-1730-ND
// Directional ports: A0, A1

const int VERT = 0; // analog
const int HORIZ = 1; // analog

int vertical, horizontal, select;

void setup() {
  Serial.begin(9600);
  Serial.println("========================================");
  Serial.println("2 axis analog 10k ohm joystick");
  Serial.println("Using ANALOG ports: 0 and 1");
  Serial.println("------------------");
  vertical = analogRead(VERT); // will be 0-1023
  horizontal = analogRead(HORIZ); // will be 0-1023
  Serial.print("vertical: ");
  Serial.print(vertical, DEC);
  Serial.print(" horizontal: ");
  Serial.println(horizontal, DEC);
  Serial.println("Done");

}

void loop() {
/*
  vertical = analogRead(VERT); // will be 0-1023
  horizontal = analogRead(HORIZ); // will be 0-1023
  Serial.print("vertical: ");
  Serial.print(vertical, DEC);
  Serial.print(" horizontal: ");
  Serial.print(horizontal, DEC);
  Serial.println("Done");
*/
}
