/*
▬▬▬▬▬ Desarrollado por Bitronics ▬▬▬▬▬▬
📱Instagram: https://cutt.ly/FWx8kcv
📱Facebook: https://cutt.ly/QWx8tC6
📹 YouTube: https://cutt.ly/aWx8g8F
 */

#include<Servo.h> //Librería para el uso de servomotores

//----- Declaramos los servos a usar -----
Servo servo_base;
Servo servo_izq;
Servo servo_der;
Servo servo_pinza;
//----------------------------------------

//----- Pines para los servomotores -----
const byte pin_servo_base = 11;
const byte pin_servo_izq = 10;
const byte pin_servo_der = 9;
const byte pin_servo_pinza = 6;
//---------------------------------------

//----- Pines para los potenciómetros -----
const byte pin_pot_base = A4;
const byte pin_pot_izq = A5;
const byte pin_pot_der = A6;
const byte pin_pot_pinza = A7;
//-----------------------------------------

void setup() {
  Serial.begin(9600); //Velocidad de baudio

  //Relacionamos los pines con los servos declarados
  servo_base.attach(pin_servo_base);
  servo_izq.attach(pin_servo_izq);
  servo_der.attach(pin_servo_der);
  servo_pinza.attach(pin_servo_pinza);
  //------------------------------------------------
}

void loop() {
  control_base();
  control_izq();
  control_der();
  control_pinza();

}

void control_base(){
  //Lectura del potenciómetro para el servo de la base
  int value = analogRead(pin_pot_base);
  //Normalización de los valores enviados
  int value_adapt = map(value, 0, 1024, 0, 180);
  //Movimiento del servomotor
  servo_base.write(value_adapt);
  delay(20);
}

void control_izq(){
  //Lectura del potenciómetro para el servo de la izquierda
  int value = analogRead(pin_pot_izq);
  //Normalización de los valores enviados
  int value_adapt = map(value, 0, 1024, 5, 70);
  //Movimiento del servomotor de la izquierda
  servo_izq.write(value_adapt);
  delay(20);
} 

void control_der(){
  //Lectura del potenciómetro para el servo de la derecha
  int value = analogRead(pin_pot_der);
  //Normalización de los valores enviados
  int value_adapt = map(value, 0, 1024, 60, 120);
  //Movimiento del servomotor de la derecha
  servo_der.write(value_adapt);
  delay(20);
}

void control_pinza(){
  //Lectura del potenciómetro para el servo de la pinza
  int value = analogRead(pin_pot_pinza);
  //Normalización de los valores enviados
  int value_adapt = map(value, 0, 1024, 30, 100);
  //Movimiento del servomotor de la pinza
  servo_pinza.write(value_adapt);
  delay(20);
}
