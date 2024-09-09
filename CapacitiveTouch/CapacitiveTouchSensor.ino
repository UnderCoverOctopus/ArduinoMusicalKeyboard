//use library manager in Arduino ide to download CapacitiveSensor by Paul Bagder & Paul Stoffregen
#include <CapacitiveSensor.h> 

CapacitiveSensor capSensor = CapacitiveSensor(4,2);// sensor input pin
int threshold = 500; 
// numbers of LED output pins
const int ledPinRed = 12; 
const int ledPinBlue = 7;

void setup() {
  // starts serial monitor
  Serial.begin(9600);
  // setting pin as output pin
  pinMode(ledPinRed,OUTPUT);
  pinMode(ledPinBlue,OUTPUT);
}

void loop() {
  // completes 30 runs before obtaining sensor value
  long sensorValue =  capSensor.capacitiveSensor(30);
  // prints sensor value to serial monitor (can use this to make changes to threshold)
  Serial.println(sensorValue);

  // if touched red light on
  if(sensorValue >threshold) {
    digitalWrite(ledPinRed,HIGH);
    digitalWrite(ledPinBlue,LOW);
  }
  // if not touched blue light on
  else {
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinBlue,HIGH);
  }
  delay(10);
}
