// Rain Sensor
#include <Servo.h>

// constants won't change
const int TRIG_PIN = A2; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = A3; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int LED_PIN  = A5; // Arduino pin connected to LED's pin
const int DISTANCE_THRESHOLD = 10; // centimeters

// variables will change:
float duration_us, distance_cm;

Servo myservo;
Servo myservo1; 

int pos = 0; 
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(A1);
  myservo1.attach(10); 
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);  // set arduino pin to output mode
}

void loop() 
{

    // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm < DISTANCE_THRESHOLD)
    digitalWrite(LED_PIN, HIGH); // turn on LED
  else
    digitalWrite(LED_PIN, LOW);  // turn off LED

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay(500);

sensorValue = analogRead(A0);
Serial.println(sensorValue);
if(sensorValue>800){
  myservo.write(0);
  myservo1.write(0);
  delay(1000);
  }
if(sensorValue<=800 && sensorValue>600)
{
   for (pos = 0; pos <= 120; pos+=1)
  { 
    myservo.write(pos);  
    myservo1.write(pos);             
    delay(3);        
  }
 
  for (pos = 120; pos >= 0; pos-=1) 
  {
    myservo.write(pos);  
    myservo1.write(pos);            
    delay(3);                    
  }
 
  delay(2000);
}

if(sensorValue<=600 && sensorValue>460)
{

 for (pos = 0; pos <= 120; pos+=1)
  { 
    myservo.write(pos); 
    myservo1.write(pos);              
    delay(3);        
  }
  for (pos = 120; pos >= 0; pos-=1) 
  {
    myservo.write(pos);  
    myservo1.write(pos);            
    delay(3);                   
  }
  
  delay(1000);
}

if(sensorValue<460){

  for (pos = 0; pos <= 120; pos+=1)
  { 
    myservo.write(pos);  
    myservo1.write(pos);             
    delay(3);        
  }
  
  for (pos = 120; pos >= 0; pos-=1)
  {
    myservo.write(pos); 
   myservo1.write(pos);             
    delay(3);                 
  }
  
  delay(100);
}

}