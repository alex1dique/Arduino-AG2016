
const int botonPin = 2; //Pin de pulsador, 
int BotonEstado = 0; //Variable con valor del pulsador
int EstadoAntes=0;//Estado del pulsador ultimo ciclo
int ContPulso=0; //Variable para contar numero de pulsos

void setup() {
Serial.begin(9600);

pinMode(botonPin, INPUT);
}

void loop(){
// Asignamos la lectura de la entrada
BotonEstado = digitalRead(botonPin);

// comprobar si esta presionado el pulsador
//de no ser asi cumulamos los pulsos y luego los imprimimos en el 
//serial.
if (BotonEstado == LOW ) {
if(EstadoAntes!=BotonEstado)
{
  EstadoAntes=BotonEstado;
  ContPulso++;
  Serial.println(ContPulso);
}

}
else {
EstadoAntes = HIGH;
}
}
