#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(4,2);
int threshold = 500;
const int ledPinRed = 12;
const int ledPinBlue = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPinRed,OUTPUT);
  pinMode(ledPinBlue,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long sensorValue =  capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);

  if(sensorValue >threshold) {
    digitalWrite(ledPinRed,HIGH);
    digitalWrite(ledPinBlue,LOW);
  }
  else {
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinBlue,HIGH);
  }
  delay(10);
}
