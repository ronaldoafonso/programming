
String incommingString;

void setup() {
  Serial.begin(9600);  
}

void loop() {
  
  if (Serial.available() > 0) {
    incommingString = Serial.readString();
    Serial.print(incommingString);
    Serial.println();
    delay(2000);
  }
  
}
