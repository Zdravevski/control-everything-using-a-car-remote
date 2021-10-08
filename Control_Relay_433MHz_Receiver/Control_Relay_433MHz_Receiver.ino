#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int relayPin = 3;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0); 
  mySwitch.setPulseLength(185);
  mySwitch.setRepeatTransmit(5);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
}

void loop() {
  if (mySwitch.available()) {
    if (mySwitch.getReceivedValue() == 8675192) {
      Serial.println("Lock button pressed");
      digitalWrite(relayPin, LOW);
    } else if (mySwitch.getReceivedValue() == 8675188) {
      Serial.println("Unlock button pressed");
      digitalWrite(relayPin, HIGH);
    }
    mySwitch.resetAvailable();
  }
}
