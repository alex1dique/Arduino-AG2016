#include <Servo.h>
Servo myservo; 
int angulo = 0; 
int led1=13;
int led2=12;
int led3=11;
void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	myservo.attach(9); 
	myservo.write(angulo);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(angulo = 0; angulo < 180; angulo += 1) 
  {                          
    myservo.write(angulo);   
    if(angulo==45) {
    Serial.print('angulo:'); 
      
    Serial.print(angulo);
      
    digitalWrite(13,HIGH);
    }
    if(angulo==90) {
    Serial.print('angulo:');
      
    Serial.print(angulo);
      
    digitalWrite(12,HIGH);
    }
    if(angulo==179) {
    Serial.print('angulo:');
      
    Serial.print(angulo);
      
    digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    angulo=0;  
    }
     
    delay(15);   
  } 
}
