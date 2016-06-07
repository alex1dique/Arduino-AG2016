#include <IRremote.h>

/*-----Constantes-----*/
int receiver = 7; // pin 1 of IR receiver to Arduino digital pin 7
#define E1 10  // Habilitar Pin 10 para el motor 1
#define E2 11  // Habilitar Pin 11 para el motor 2

#define I1 9  // Control pin 1 para motor 1
#define I2 8  // Control pin 2 para motor 1
#define I3 13 // Control pin 1 para motor 2
#define I4 12 // Control pin 2 para motor 2
int ledG =5;//led verde
int ledR =4;//led roja 

IRrecv irrecv(receiver);           // creando instancia para 'irrecv'
decode_results Codigo;            // creando instancia para 'decode_results'



void setup()
{
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledR, OUTPUT);
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
    
    Serial.begin(9600);
    irrecv.enableIRIn(); // Iniciar el receptor

}//fin setup


void loop()   //BUCLE : funciona de manera constante
{
   if (irrecv.decode(&Codigo))
        {
        Serial.println(Codigo.value);
        delay(50);
        irrecv.resume();
        } 
     if(Codigo.value==2575714394)//flecha arriva  
      {
      //Adelante
      digitalWrite(E1, LOW);
      digitalWrite(E2, LOW);
      
      digitalWrite(E1, HIGH);
      digitalWrite(E2, HIGH);

      digitalWrite(I1, HIGH);
      digitalWrite(I2, LOW);
      digitalWrite(I3, HIGH);
      digitalWrite(I4, LOW);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledR, HIGH);
      }   
      
      if(Codigo.value==476746140)//flecha abajo 
      {
      //Abajo
      // change direction

      digitalWrite(E1, LOW);
      digitalWrite(E2, LOW);
      //leds para indicar que se cambia el sentido de los motores
      digitalWrite(ledG, LOW);
      digitalWrite(ledR, LOW);
      delay(500);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledR, HIGH);
      delay(500);
      
      digitalWrite(E1, HIGH);
      digitalWrite(E2, HIGH);

      digitalWrite(I1, LOW);
      digitalWrite(I2, HIGH);
      digitalWrite(I3, LOW);
      digitalWrite(I4, HIGH);
      } 
      
      if(Codigo.value==3398796026)//STOP
      {
        //STOP
      digitalWrite(E1, LOW);
      digitalWrite(E2, LOW);
      
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      digitalWrite(I3, LOW);
      digitalWrite(I4, LOW);
      //leds apagadas indican q se detubo los motores
      digitalWrite(ledG, LOW);
      digitalWrite(ledR, LOW);
      }
      
       if(Codigo.value==1587577092)//STOP motor 1
      {
      digitalWrite(E2, HIGH);
      digitalWrite(E1, LOW);
      
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      digitalWrite(I3, HIGH);
      digitalWrite(I4, LOW);
      //leds apagadas indican q se detubo los motores
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, HIGH);
      }
      
       if(Codigo.value==1320813602)//STOP motor 2
      {
      digitalWrite(E1, HIGH);
      digitalWrite(E2, LOW);
      
      digitalWrite(I3, LOW);
      digitalWrite(I4, LOW);
      digitalWrite(I1, HIGH);
      digitalWrite(I2, LOW);
      //leds apagadas indican q se detubo los motores
      digitalWrite(ledG, LOW);
      digitalWrite(ledR, HIGH);
      }
      
      if(Codigo.value==3189035290)
      {
      digitalWrite(E1, LOW);
      digitalWrite(E2, LOW);
      delay(5000);
      analogWrite(E1,150);//low spedd
      analogWrite(E2,150);//
      digitalWrite(E1,HIGH );
      digitalWrite(E2,HIGH );
      digitalWrite(I1, HIGH);
      digitalWrite(I2, LOW);
      digitalWrite(I3, HIGH);
      digitalWrite(I4, LOW);
      
      }
      
       if(Codigo.value==510371368)
      {
        
      digitalWrite(E1, LOW);
      digitalWrite(E2, LOW);
      delay(5000);
      analogWrite(E1,255);//full speed
      analogWrite(E2,255);//
      digitalWrite(E1,HIGH );
      digitalWrite(E2,HIGH );
      digitalWrite(I1, HIGH);
      digitalWrite(I2, LOW);
      digitalWrite(I3, HIGH);
      digitalWrite(I4, LOW);
      
      
    
      }
}      



