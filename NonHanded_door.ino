#include <Servo.h>
#define trigPin 3
#define echoPin 2
Servo myservo; 

int pos = 0;    
long duration;
int distance;

void setup() {
  myservo.attach(9);  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic TEST"); // print some text in Serial Monitor
  Serial.println(" Created by Hasan Bilgen");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2; 

 if (distance > 40) {
    
      Serial.println("not touched");
    
          
    if(pos == 140){
      for (pos = 140; pos >= 70; pos -= 1) { 
    myservo.write(pos);              
      }   
  }   
    
  }
  
  
  
   if (distance <= 40) {   
    pos=0; 
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("OPENING THE DOOR!");
     for (pos = 0; pos <= 140; pos += 1) { 
    myservo.write(pos);              
    }
    pos=140;
    delay(1000);
  }
 
}
