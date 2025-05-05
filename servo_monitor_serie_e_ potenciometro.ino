/*
* Prueba del funcionamiento de un servomotor
* empleando la libreria <Servo.h>. El servo se 
* controla medinte un potencometro conecado en A5,
* usando el comando map combertimos los valores del
* potenciomero 0-1023 en una señal de 0-210 que se 
* divide en grupos en cada uno aumenta 10º asta llegar a 180º
* tanbien funcionan de forma inversa; Otra manera de control 
* conjuntamente pero no ala vez que el potenciometro teniendo 
* prioridad es el control atraves del monitor serie por el cual 
* se escribe una palabra de la dirección deseada (derecha, izquierda, 
* diagonal derecha, diagonal izquierad, centro o incluso el numero entero entre 0-180 del angulo) 
* todo esto nos permite posicionar el servo.
* PIN 3 - Salida de control del servo (CTRL)
* PIN A5 - Enrada analogica potenciometro
*
* Rey Mirón Brais
*
* 05 / 05 / 2025
*/

#include <Servo.h>

//Pin de control del servo PIN 3
//Pin de entrada anaologica potenciometro
#define CTRL 3
#define POT A5 
// Definir valores enteros (int)
int estado = 0; 
int serial = 0;
int estadoanterior = 0;
int valor = 0;
Servo motor;

void setup(){
  motor.attach(CTRL); 
  motor.write(0); // Posicionar motor en 0
  estadoanterior = analogRead(POT);
  Serial.begin(9600); // Activación del monitor serie
}
void loop(){
  if(Serial.available() >0){
  String serial = Serial.readStringUntil('\n'); // Ler un conjunto de letras desde el monitor serie y guardarlo en (estado)
  serial.trim();
    if(serial == "izquierda"){  // Si el etsado (palabra escrita en el monitor) = izquierda 
      motor.write(180); // Gira el motor a 180º
    }
    else if(serial == "derecha"){ // Si el etsado (palabra escrita en el monitor) =  derecha
      motor.write(0); // Gira el motor a 0º
    }
    else if(serial == "centro"){ // Si el etsado (palabra escrita en el monitor) = centro 
      motor.write(90); // Gira el motor a 90º
    }
    else if(serial == "diagonal derecha"){ // Si el etsado (palabra escrita en el monitor) = diagonal derecha 
      motor.write(45); // Gira el motor a 45º
    }
    else if(serial == "diagonal izquierda"){ // Si el etsado (palabra escrita en el monitor) = diagonal izquierda 
      motor.write(135); // Gira el motor a 135º 
    }
    else{
    int angulo = serial.toInt(); // Ler un número entero desde el monitor serie
    if (angulo >= 0 && angulo <= 180) { // Siempre que el valor numerico introducido en el monitor serie sea >=0 pero <=180
      motor.write(angulo); // Girar el motor al angulo especificado (angulo)
    }
    }
    delay(6670); // Retardo de 30ms
  }
  else {
  estado = analogRead(POT); // Leer potenciometro y guardar en estado (numero entero)
    if(abs(estado - estadoanterior) > 5){ // Condicion para desactivar potenciometro cuando no se mueve (si no hay una diferencia < o > de 5 del estado actual con el anteior no se aplica el potenciometro)
      estadoanterior = estado; // Canbiar estadoanterior a estado actual 
    valor = map(estado, 0, 1023, 0, 210);
    if(valor >= 0 && valor <= 10){ //Condiciones para cambiar el anguo de 10º segun el vaor del POT asa 180º
      motor.write(0);
    }
    if(valor >= 10 && valor <= 20){
      motor.write(10);
    }
    if(valor >= 20 && valor <= 30){
      motor.write(20);
    }
    if(valor >= 30 && valor <= 40){
      motor.write(30);
    }
    if(valor >= 40 && valor <= 50){
      motor.write(40);
    }
    if(valor >= 50 && valor <= 60){
      motor.write(50);
    }
    if(valor >= 60 && valor <= 70){
      motor.write(60);
    }
    if(valor >= 70 && valor <= 80){
      motor.write(70);
    }
    if(valor >= 80 && valor <= 90){
      motor.write(80);
    }
    if(valor >= 90 && valor <= 100){
      motor.write(90);
    }
    if(valor >= 100 && valor <= 110){
      motor.write(100);
    }
    if(valor >= 110 && valor <= 120){
      motor.write(110);
    }
    if(valor >= 120 && valor <= 130){
      motor.write(120);
    }
    if(valor >= 130 && valor <= 140){
      motor.write(130);
    }
    if(valor >= 140 && valor <= 150){
      motor.write(140);
    }
    if(valor >= 150 && valor <= 160){
      motor.write(150);
    }
    if(valor >= 160 && valor <= 170){
      motor.write(160);
    }
    if(valor >= 170 && valor <= 180){
      motor.write(170);
    }
    if(valor >= 180 && valor <= 190){
      motor.write(180);
    }
    }
  Serial.print("Estado POT: "); Serial.print(estado); Serial.print("  "); Serial.print("Valor: "); Serial.println(valor);
  delay(6670);
  }
}
