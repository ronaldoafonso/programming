#include <EEPROM.h>

String line;
String command;
String address;
String value;

void setup() {
    int i;

    for (i = 0 ; i < EEPROM.length() ; i++) {
        EEPROM.write(i, 0);
    }
    Serial.begin(9600);
}

void loop() {

    if (Serial.available() > 0) {
        line = Serial.readString();
        getCommand(line + '\n');

        if (command == "read") {
            exec_read(address.toInt());
        } else if (command == "write") {
            exec_write(address.toInt(), value.toInt());
        } else {
            Serial.println("Invalid command.");
        }
    }
}

void exec_read(int address) {
    int value;

    value = EEPROM.read(address);
    Serial.print("Value read: ");
    Serial.println(value);
}

void exec_write(int address, int value) {
    EEPROM.write(address, value);
    Serial.print("Value written: ");
    Serial.println(value);
}

void getCommand(String line) {
    int i, j, w;

    for(i = 0; i <= line.length(); i++) {
        if (line[i] == ' ') {
            command = line.substring(0, i);
            break;
        }
    }

    i++;
    for(j = i; j <= line.length(); j++) {
        if (line[j] == ' ' || line[j] == '\n') {
            address = line.substring(i, j);
            break;
        }
    }

    if (line[j] == ' ') {
        j++;
        for(w = j; w <= line.length(); w++) {
            if (line[w] == '\n') {
                value = line.substring(j, w);
                break;
            }
        }
    }
}
