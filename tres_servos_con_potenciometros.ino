/*
* Prueba del funcionamiento de tres servomotores
* cada  uno de ellos estan controlados por un potenciometro 
* en este caso se simulaba el funcionmiento de una garra robotica 
* por lo que cada servo debia tener una precision distinta 
* el servo horizontal tiene una precisión de 12°; El servo
* vertical de 5° y el servo de la pinza una precision de 0.5°.
* Todo esto es reactivo como maximo 8 veces por segundo para evitar 
* daños en los engranages de los servomotores.
*
* Pnciomeotetro horizontal PIN: A3
* Pnciomeotetro vertical PIN: A4
* Pnciomeotetro pinza PIN: A5
*
* Rey Mirón Brais
*
* 08 / 05 / 2025
*/
// Comando para añadir libreria Servo.h
#include <Servo.h> 

// Definicion de los pines de entrada de cada servo
#define CTRL1 3
#define CTRL2 5
#define CTRL3 6
// Definicion de los pines de entrada de cada potenciómetro
#define POT1 A3
#define POT2 A4
#define POT3 A5

// Definir valores enteros (int) 
int estado1 = 0;
int estado2 = 0;
int estado3 = 0;
int valor = 0;
Servo motorH;
Servo motorV;
Servo motorP;

void setup(){
  motorH.attach(CTRL1); 
  motorV.attach(CTRL2); 
  motorP.attach(CTRL3); 
  motorH.write(0); // Posicionar servomotores en 0º
  motorV.write(0);
  motorP.write(0);
  Serial.begin(9600); // Activación del monitor serie
}
void loop(){
  estado1 = analogRead(POT1); // Leer potenciometro1 y guardar valor en estado1 
  int valorA = map(estado1, 0, 1023, 0, 15); // Mapear y hacer grupos de 12° (0-180°)
  valorA = valorA * 12;
  motorH.write(valorA); // Ecribir valorA como valor de salida al motorH
  estado2 = analogRead(POT2); // Leer potenciometro2 y guardar valor en estado2 
  int valorB = map(estado2, 0, 1023, 0, 36); // Mapear y hacer grupos de 5° (0-180°)
  valorB = valorB * 5;
  motorV.write(valorB); // Ecribir valorB como valor de salida al motorV
  estado3 = analogRead(POT3); // Leer potenciometro3 y guardar valor en estado3
  int valorC = map(estado3, 0, 1023, 0, 360); // Mapear y hacer grupos de 0.5° (0-180°)
  valorC = valorC * 0.5;
  motorP.write(valorC); // Ecribir valorC como valor de salida al motorP
  //Sacar por monitor serie valores de las salidas
  Serial.print("Motor Horizontal: "); Serial.print(valorA); Serial.print("     "); 
  Serial.print("Motor Vertical: "); Serial.print(valorB); Serial.print("     "); 
  Serial.print("Motor Pinza: "); Serial.println(valorC);
  delay(125); // Retardo para non dañar os servos
}
