/*
* Prueba del funcionamiento de un servomotor
* empleando la libreria <Servo.h>. El servo se 
* controla medinte el monitor serie introduciendo 
* palabras de dirección  derecha: 0º  izquierda: 180
* centro: 90º  diagonal izquierda: 135  diagonal derecha: 45º,
* tambien se puede controlar de forma numerica indicando los 
* grados de rotación del servo.
* PIN 3 - Salida de control del servo (CTRL)
*
* Rey Mirón Brais
*
*02 / 05 / 2025
*/

#include <Servo.h>

//Pin de control del servo PIN 3
#define CTRL 3 

Servo motor;

void setup(){
 motor.attach(CTRL); 
  motor.write(90); // Posicionar motor en el centro
 Serial.begin(9600); // Activación del monitor serie
}
void loop(){
  if(Serial.available() >0){
  String estado = Serial.readStringUntil('\n'); // Ler un conjunto de letras desde el monitor serie y guardarlo en (estado)
  estado.trim();
    if(estado == "izquierda"){  // Si el etsado (palabra escrita en el monitor) = izquierda 
      motor.write(180); // Gira el motor a 180º
    }
    else if(estado == "derecha"){ // Si el etsado (palabra escrita en el monitor) =  derecha
      motor.write(0); // Gira el motor a 0º
    }
    else if(estado == "centro"){ // Si el etsado (palabra escrita en el monitor) = centro 
      motor.write(90); // Gira el motor a 90º
    }
    else if(estado == "diagonal derecha"){ // Si el etsado (palabra escrita en el monitor) = diagonal derecha 
      motor.write(45); // Gira el motor a 45º
    }
    else if(estado == "diagonal izquierda"){ // Si el etsado (palabra escrita en el monitor) = diagonal izquierda 
      motor.write(135); // Gira el motor a 135º 
    }
    else{
    int angulo = estado.toInt(); // Ler un número entero desde el monitor serie
    if (angulo >= 0 && angulo <= 180) { // Siempre que el valor numerico introducido en el monitor serie sea >=0 pero <=180
      motor.write(angulo); // Girar el motor al angulo especificado (angulo)
    }
    }
    delay(30); // Retardo de 30ms
  }
}
