#include <IRremote.h>
#include <Ultrasonic.h>

/*-----Constantes-----*/
int receiver = 3; // pin 3 del arduino para el receptor IR
#define E1 10    // Habilitar Pin 10 para el motor 1(Enable1)
#define E2 11   // Habilitar Pin 11 para el motor 2(Enable2)

#define I1 9  // Control pin 1 para motor 1(In1)
#define I2 8  // Control pin 2 para motor 1(In2)
#define I3 13  // Control pin 1 para motor 2(In3)
#define I4 12 // Control pin 2 para motor 2(In4)

#define TRIGGER_PIN  5//Pin 5 Trig ultrasonido
#define ECHO_PIN     4//pin 4 Echo ultrasonido

int ledPin = 6;

IRrecv irrecv(receiver);// creando instancia para 'irrecv'
decode_results Codigo;            // creando instancia para 'decode_results'
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup()
    {
    for(int i=8;i<=13;i++) 
    {
    pinMode(i, OUTPUT);  
    }
    pinMode(ECHO_PIN, INPUT);    
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(receiver, INPUT);
    pinMode(ledPin, OUTPUT);
    
    
    
    attachInterrupt(1, IR,  HIGH);//interrupción pin 3 (IR pin Data)
    Serial.begin(9600);
    irrecv.enableIRIn(); // Iniciar el receptor 
   }

void loop()
{
    float cmMsec;
    long microsec = ultrasonic.timing();
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
   
    if ( cmMsec>= 500 || cmMsec <= 0)
        {  // si la distancia es mayor a 500cm o menor a 0cm 
        Serial.println("Medicion no confiable"); // cuando la distancia es mayor de 5 metros la medicion no es exapta
        }
    else 
    {
        Serial.print(cmMsec);           // envia el valor de la distancia por el puerto serial
        Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
        digitalWrite(6, 0);               // en bajo el pin 13
     }
  
    if (cmMsec<= 70 && cmMsec >= 1)
    {
        digitalWrite(6, 1);                     // en alto el pin 6 si la distancia es menor a 10cm
        Serial.println("Alarma.......");         // envia la palabra Alarma por el puerto serial
           Serial.println("Obstaculo");
    digitalWrite(E1, LOW);
    digitalWrite(E2, LOW);
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, LOW);
    delay(2000);
    digitalWrite(E1, LOW);
    digitalWrite(E2, LOW);
    digitalWrite(E1, HIGH);
    digitalWrite(E2, HIGH);
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
    digitalWrite(6, 1);
    delay(4000);
    digitalWrite(E1, LOW);
    digitalWrite(E2, LOW);
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, LOW);
     }
     delay(400);                                // espera 400ms para que se logre ver la distancia en la consola
}

void IR()
{
    if (irrecv.decode(&Codigo))
        {
        Serial.println(Codigo.value);
        delay(50);
        irrecv.resume();
        } 
    if(Codigo.value== 2575714394)//flecha arriva  
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
      }
   if(Codigo.value== 476746140)//flecha abajo
      {
      //Atras
      digitalWrite(E1, LOW);
      digitalWrite(E2, LOW);
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
      }
   if(Codigo.value==1320813602)//STOP motor 1
      {
      digitalWrite(E2, HIGH);
      digitalWrite(E1, LOW);
      
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      digitalWrite(I3, HIGH);
      digitalWrite(I4, LOW);
      }
      
    if(Codigo.value==1587577092)//STOP motor 2
      {
      digitalWrite(E1, HIGH);
      digitalWrite(E2, LOW);
      
      digitalWrite(I3, LOW);
      digitalWrite(I4, LOW);
      digitalWrite(I1, HIGH);
      digitalWrite(I2, LOW);
      }
    if(Codigo.value==3189035290)
       {
       digitalWrite(E1, LOW);
       digitalWrite(E2, LOW);
      
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
       analogWrite(E1,255);//full speed
       analogWrite(E2,255);//
       digitalWrite(E1,HIGH );
       digitalWrite(E2,HIGH );
       digitalWrite(I1, HIGH);
       digitalWrite(I2, LOW);
       digitalWrite(I3, HIGH);
       digitalWrite(I4, LOW);
      
      }
   digitalWrite(6, 1);
   digitalWrite(3,LOW);
}
