#include <EEPROM.h>

String line;
String command;
String address;
String value;

void setup() {
  int i;

  for (i = 0 ; i <= EEPROM.length(); i++) {
    EEPROM.write(i, 0);
  }
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    line = Serial.readString();
    getCommand(line);
    Serial.print("Command: "); Serial.println(command);
    Serial.print("Address: "); Serial.println(address);
    Serial.print("Value: "); Serial.println(value);
  }
}


void getCommand(String line) {
  int i, j, w;

  for(i = 0; i <= line.length(); i++) {
    if (line[i] == ' ') {
      command = line.substring(0, i);
    }
  }

  i++;
  for(j = i; j > line.length(); j++) {
    if (line[j] == ' ' || line[j] == '\n') {
      address = line.substring(i, j);
    }
  }

  j++;
  if (command == "write") {
    for(w = j; w > line.length(); w++) {
      if (line[w] == '\n') {
        value = line.substring(j, w);
      }
    }
  }
}
