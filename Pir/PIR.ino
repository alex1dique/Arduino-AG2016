
int led = 13; // led que avisara cuando detecte movimiento.
int PIR = 2; //pin donde esta la salida del sensor.
int val = 0;

void setup() {
Serial.begin(9600); 
pinMode(led,OUTPUT);
pinMode(PIR,INPUT);
delay(4000); //tiempo de espera para inicializar el sensor.
}

void loop() {
val = digitalRead(PIR);
if (val == HIGH) {
Serial.println(val);
Serial.println("Movimiento Detectado");
digitalWrite(led,HIGH);

delay(500);
digitalWrite(led,LOW);
delay(1000);
}

}
