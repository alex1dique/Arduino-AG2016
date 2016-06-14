
//variables 
int ledG = 13;//declarando pin 13 para la led green
int ledY = 12;//declarando pin 12 para la led yellow
int ledR = 11;//declarando pin 11 para la led red

// the setup routine runs once when you press reset:
void setup() {
  
    // Inicializar el pin digital como salida
    pinMode(ledG, OUTPUT);//pin 13
    pinMode(ledY, OUTPUT);//pin 12
    pinMode(ledR, OUTPUT);//pin 11
  
}

void led_yellow(){
  
  //YELLOW LED
    for (int i=0;i<5;i++) {
        digitalWrite(ledY, HIGH);  // encender el LED 
        delay(500);               // espera 1 segundo
        digitalWrite(ledY, LOW);   // apagar el LED
        delay(500);               // espera 1 segundo      
      }   
                  
  }
// La rutina de bucle se ejecuta una y otra vez para siempre :
void loop() {
  
    //GREEN LED
    digitalWrite(ledG, HIGH);   // encender el LED 
    delay(10000);               // espera 10 segundos
    digitalWrite(ledG, LOW);    // apagar el LED 
                
    //YELLOW LED
    led_yellow();//llamando funcion led_yellow
  
    //RED LED
    digitalWrite(ledR, HIGH);   // encender el LED
    delay(10000);               // espera 10 segundos
    digitalWrite(ledR, LOW);    // apagar el LED
  
    //YELLOW LED
    led_yellow();//llamando funcion led_yellow
  
}

