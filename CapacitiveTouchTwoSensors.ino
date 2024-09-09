#include <CapacitiveSensor.h>
CapacitiveSensor capSensorHeart = CapacitiveSensor(3,2);// capacitor pin of heart
CapacitiveSensor capSensorStar = CapacitiveSensor(4,2); // capacitor pin of star
int heartThreshHold = 600;
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


  // When heart is touched
  if(sensorValueHeart >threshold ) { 

    digitalWrite(ledPinRed,LOW);
    digitalWrite(ledPinBlue,HIGH);
  }
  //When star is touched
  else if (sensorValueHeart < 200) { 

    digitalWrite(ledPinRed, HIGH);
    digitalWrite(ledPinBlue,LOW);
  }
  else {

    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinBlue,LOW);
  }

  delay(10);
}
