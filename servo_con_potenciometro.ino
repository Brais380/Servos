/*
* Prueba del funcionamiento de un servomotor
* empleando la libreria <Servo.h>. El servo se 
* controla medinte un potencometro conecado en A5
* usando el comando map combertimos los valores del
* potenciomero 0-1023 en una seña de 0-210 que se 
* divide en grupos en cada uno se aumena 10º asa legar a 180º
* tanbien funcionan de forma inversa.
* PIN 3 - Salida de control del servo (CTRL)
* PIN A5 - Enrada analogica potenciometro
*
* Rey Mirón Brais
*
* 03 / 05 / 2025
*/

#include <Servo.h>

//Pin de control del servo PIN 3
//Pin de entrada anaologica potenciometro
#define CTRL 3
#define POT A5 

int estado = 0; // (esado) Vaor entero del potenciometro
Servo motor;

void setup(){
 motor.attach(CTRL); 
  motor.write(180); // Posicionar motor en el centro
 Serial.begin(9600); // Activación del monitor serie
}
void loop(){
  estado = analogRead(POT); // Leer potenciometro y guardar en estado (numero entero)
  int valor = map(estado, 0, 1023, 0, 210);
    if(valor >= 0 && valor <= 10){ //Condiciones para cambiar el anguo de 10º segun el vaor del POT asa 180º
      motor.write(180);
    }
    if(valor >= 10 && valor <= 20){
      motor.write(170);
    }
    if(valor >= 20 && valor <= 30){
      motor.write(160);
    }
    if(valor >= 30 && valor <= 40){
      motor.write(150);
    }
    if(valor >= 40 && valor <= 50){
      motor.write(140);
    }
    if(valor >= 50 && valor <= 60){
      motor.write(130);
    }
    if(valor >= 60 && valor <= 70){
      motor.write(120);
    }
    if(valor >= 70 && valor <= 80){
      motor.write(110);
    }
    if(valor >= 80 && valor <= 90){
      motor.write(100);
    }
    if(valor >= 90 && valor <= 100){
      motor.write(90);
    }
    if(valor >= 100 && valor <= 110){
      motor.write(80);
    }
    if(valor >= 110 && valor <= 120){
      motor.write(70);
    }
  if(valor >= 120 && valor <= 130){
      motor.write(60);
    }
  if(valor >= 130 && valor <= 140){
      motor.write(50);
    }
  if(valor >= 140 && valor <= 150){
      motor.write(40);
    }
  if(valor >= 150 && valor <= 160){
      motor.write(30);
    }
  if(valor >= 160 && valor <= 170){
      motor.write(20);
    }
  if(valor >= 170 && valor <= 180){
      motor.write(10);
    }
  if(valor >= 180 && valor <= 190){
      motor.write(0);
    }
  Serial.print("Estado POT: "); Serial.print(estado); Serial.print("  "); Serial.print("Valor: "); Serial.println(valor);
  delay(125);
}
