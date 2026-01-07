// RECEIVER FINAL CODE
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
RH_ASK driver;


void setup()
{
  pinMode(A5, OUTPUT);
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{

  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE); 
   
  uint8_t buf[8];
  uint8_t buflen = sizeof(buf);
  String x;
  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    int i;
    // Message with a good checksum received, dump it.
    Serial.print(" Message Received: ");
    x=((String)(char*)buf);
    x.trim();
    Serial.println(x+ " :"+x.length());   
    if(x=="Forward!")
      {
          Serial.println("MOVING FORWARD");
        motor1.setSpeed(500);
        motor2.setSpeed(500);
        motor3.setSpeed(255);
        motor4.setSpeed(255);
         
          motor1.run(BACKWARD);
          motor2.run(BACKWARD); 
          motor3.run(RELEASE); 
          motor4.run(RELEASE);
          delay(1000);
        }
               
    else if(x=="Backward")
    {
          Serial.println("MOVING BACKWARD");
        motor1.setSpeed(500);
        motor2.setSpeed(500);
        motor3.setSpeed(255);
        motor4.setSpeed(255);
        
          motor1.run(FORWARD);
          motor2.run(FORWARD); 
          motor3.run(RELEASE); 
          motor4.run(RELEASE);
          delay(1000);
        }      
    else if(x=="RightFor")
    {  
      Serial.println("TURNING TOWARDS RIGHT SIDE");
        motor1.setSpeed(500);
        motor2.setSpeed(500);
        motor3.setSpeed(255);
        motor4.setSpeed(255);

        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
      delay(1000);
    }

    else if(x=="LeftForw")
    { 
      Serial.println("TURNING TOWARDS LEFT SIDE");  
        motor1.setSpeed(500);
        motor2.setSpeed(500);
        motor3.setSpeed(255);
        motor4.setSpeed(255);

        motor3.run(FORWARD);
        motor4.run(FORWARD);
        motor2.run(BACKWARD);
        motor1.run(BACKWARD);
        delay(1000);
    }

        
    else if(x=="RightBac")
    {  
      Serial.println("TURNING TOWARDS RIGHT SIDE"); 
        motor1.setSpeed(500);
        motor2.setSpeed(500);
        motor3.setSpeed(255);
        motor4.setSpeed(255);

        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
      delay(1000);
    }
    else if(x=="LeftBack")
    { 
      Serial.println("TURNING TOWARDS LEFT SIDE");
        motor1.setSpeed(500);
        motor2.setSpeed(500);
        motor3.setSpeed(255);
        motor4.setSpeed(255);

        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
        delay(1000);
    }
    else if(x=="**Stop**")
    {  
        Serial.println("BREAK");
        motor1.setSpeed(255);
        motor2.setSpeed(255);
        motor3.setSpeed(255);
        motor4.setSpeed(255);
 
        motor1.run(RELEASE);
        motor2.run(RELEASE); 
        motor3.run(RELEASE);
        motor4.run(RELEASE);
        delay(1000);
    }   
  } 
}