//use library manager in Arduino ide to download CapacitiveSensor by Paul Bagder & Paul Stoffregen
#include <CapacitiveSensor.h>

CapacitiveSensor capSensorHeart = CapacitiveSensor(3,2);// capacitor pin of heart (sensor one)
CapacitiveSensor capSensorStar = CapacitiveSensor(4,2); // capacitor pin of star (sensor two)
int heartThreshHold = 600; /
int starThreshHold = 200;
const int ledPinRed = 11; //pin number of pin connected to red led
const int ledPinBlue = 10; //pin number of pin connected to blue led
const int runs = 30;

void setup() {
  
  // start connection to 9600 serial monitor
  Serial.begin(9600);

  //initialise outputs
  pinMode(ledPinRed,OUTPUT); 
  pinMode(ledPinBlue,OUTPUT);
}

void loop() {

  //get sensor values after 30 runs
  long sensorValueHeart =  capSensorHeart.capacitiveSensor(runs);

  // print values to serial monitor
  Serial.println(sensorValueHeart);


  // When heart is touched turn on blue LED
  if(sensorValueHeart >threshold ) { 

    digitalWrite(ledPinRed,LOW);
    digitalWrite(ledPinBlue,HIGH);
  }
  //When star is touched turn on red LED
  else if (sensorValueHeart < 200) { 

    digitalWrite(ledPinRed, HIGH);
    digitalWrite(ledPinBlue,LOW);  
  }
  // no LEDs are on
  else {

    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinBlue,LOW);
  }

  delay(10);
}
