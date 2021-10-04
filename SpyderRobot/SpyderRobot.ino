#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//Usamos la dirección "0x40" de nuestra placa
Adafruit_PWMServoDriver servo = Adafruit_PWMServoDriver(0x40);

int pos_0 = 102;   //Ancho de pulso equivalente al ángulo 0°
int pos_180 = 512; //Ancho de pulso equivalente al ángulo 180°

//---------- PATA IZQUIERDA DELANTERA ----------
const byte PataAdelanteIzquierda = 0;
const byte RodillaAdelanteIzquierda = 1;
const byte PiernaAdelanteIzquierda = 2;
//----------------------------------------------

//---------- PATA IZQUIERDA TRASERA ----------
const byte PataAtrasIzquierda = 3;
const byte RodillaAtrasIzquierda = 4;
const byte PiernaAtrasIzquierda = 5;
//---------------------------------------------

//---------- PATA DERECHA DELANTERA ----------
const byte PataAdelanteDerecha = 6;
const byte RodillaAdelanteDerecha = 7;
const byte PiernaAdelanteDerecha = 8;
//---------------------------------------------

//---------- PATA DERECHA TRASERA ----------
const byte PataAtrasDerecha = 9;
const byte RodillaAtrasDerecha = 10;
const byte PiernaAtrasDerecha = 11;

void setup() {
  Serial.begin(9600);
  
  servo.begin(); //Inicializamos nuestra variable
  servo.setPWMFreq(50); //Asignamos una frecuencia PWM de 50Hz

  //Posición inicial
  pos_initial();
  delay(50);
  //walkAdelante();
}

void loop() {
  //walkAdelante();
  delay(100);
}

void set_servo(int n_servo, int angle){
  //Pasamos los pulsos a ángulos
  int duty = map(angle, 0, 180, pos_0, pos_180);
  //(servo, pos_inicial_pulso, pos_final_pulso)
  servo.setPWM(n_servo, 0, duty); 
}

void pos_initial(){
  
  //---------- SPYDER EMPIEZA ECHADO ----------
  set_servo(PataAdelanteIzquierda, 90); delay(20);
  set_servo(RodillaAdelanteIzquierda, 90); delay(20);
  set_servo(PiernaAdelanteIzquierda, 90); delay(20); //60
  
  set_servo(PataAtrasIzquierda, 90); delay(20);
  set_servo(RodillaAtrasIzquierda, 90); delay(20);
  set_servo(PiernaAtrasIzquierda, 90); delay(20); //120
  
  set_servo(PataAdelanteDerecha, 90); delay(20);
  set_servo(RodillaAdelanteDerecha, 90); delay(20);
  set_servo(PiernaAdelanteDerecha, 90); delay(20);//120
  
  set_servo(PataAtrasDerecha, 90); delay(20);
  set_servo(RodillaAtrasDerecha, 90); delay(20);
  set_servo(PiernaAtrasDerecha, 90); delay(20);//60

  delay(1000);

  //---------- SPYDER SE PONE DE PIE ----------
  
  for(int i=90; i>=0; i--){
    set_servo(PataAdelanteDerecha, i);
    delay(10);
  }

  for(int i=90; i>=0; i--){
    set_servo(PataAtrasIzquierda, i);
    delay(10);
  }
  
  for(int i=90; i<=180; i++){
    set_servo(PataAdelanteIzquierda, i);
    delay(10);
  }

  for(int i=90; i<=180; i++){
    set_servo(PataAtrasDerecha, i);
    delay(10);
  }

  delay(1000);
  
}


void walkAdelante(){
  
  //---------- SPYDER WALK FRONT ----------

  //---------- PRIMERA PATA ----------
  for(int i=90; i>=30; i--){
    set_servo(RodillaAdelanteDerecha, i);
    delay(10);
  }

  for(int i=120; i<=170; i++){
    set_servo(PiernaAdelanteDerecha, i);
    delay(10);
  }

    for(int i=30; i<=90; i++){
    set_servo(RodillaAdelanteDerecha, i);
    delay(10);
  }

  //---------- SEGUNDA PATA ----------
  for(int i=90; i>=30; i--){
    set_servo(RodillaAtrasIzquierda, i);
    delay(10);
  }

  for(int i=120; i>=60; i--){
    set_servo(PiernaAtrasIzquierda, i);
    delay(10);
  }

    for(int i=30; i<=90; i++){
    set_servo(RodillaAtrasIzquierda, i);
    delay(10);
  }

  
  //---------- TERCERA PATA ----------
  for(int i=90; i<=150; i++){
    set_servo(RodillaAdelanteIzquierda, i);
    delay(10);
  }

  for(int i=60; i>=30; i--){
    set_servo(PiernaAdelanteIzquierda, i);
    delay(10);
  }

  for(int i=150; i>=90; i--){
    set_servo(RodillaAdelanteIzquierda, i);
    delay(10);
  }

  //---------- CUARTA PATA ----------

  for(int i=90; i<=150; i++){
    set_servo(RodillaAtrasDerecha, i);
    delay(10);
  }

  for(int i=60; i<=150; i++){
    set_servo(PiernaAtrasDerecha, i);
    delay(10);
  }

  for(int i=150; i>=90; i--){
    set_servo(RodillaAtrasDerecha, i);
    delay(10);
  }

  //---------- DESPLAZAMIENTO BASE ----------
  set_servo(PiernaAtrasDerecha, 60);
  set_servo(PiernaAtrasIzquierda, 120);
  set_servo(PiernaAdelanteDerecha, 120);
  set_servo(PiernaAdelanteIzquierda, 60);

  delay(500);
 
}
