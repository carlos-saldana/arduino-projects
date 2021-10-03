#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//Usamos la dirección "0x40" de nuestra placa
Adafruit_PWMServoDriver servo = Adafruit_PWMServoDriver(0x40);

int pos_0 = 102;   //Ancho de pulso equivalente al ángulo 0°
int pos_180 = 512; //Ancho de pulso equivalente al ángulo 180°

//---------- PINES ----------
const byte cabeza = 0; //20 - 80
const byte cuello = 1; //20 - 160
const byte cola = 2;   //50 - 130

const byte femur_ad_izq = 3;
const byte femur_ad_der = 4;
const byte femur_atr_der = 5;
const byte femur_atr_izq = 6;

const byte pie_ad_izq = 7;
const byte pie_ad_der = 8;
const byte pie_atr_der = 9;
const byte pie_atr_izq = 10;
//---------------------------

//---------- FUNCIONES ----------
void set_servo(int n_servo, int angle);
void pos_initial();
void pos_rest();
void pos_up();

//-------------------------------

void setup() {
  Serial.begin(9600);
  
  servo.begin();        //Inicializamos nuestra variable
  servo.setPWMFreq(50); //Asignamos una frecuencia PWM de 50Hz

}

void loop() {
  
  pos_initial();
  delay(1000);
  pos_rest();
  delay(1000);
  pos_up();

}

//----- Position initial -----
void pos_initial(){
  
  set_servo(cabeza, 20); delay(10);
  set_servo(cuello, 90); delay(10);
  set_servo(cola, 90); delay(10);

  set_servo(femur_ad_izq, 90); delay(10);
  set_servo(femur_ad_der, 90); delay(10);
  set_servo(femur_atr_der, 90); delay(10);
  set_servo(femur_atr_izq, 90); delay(10);
  
  set_servo(pie_ad_izq, 90); delay(10);
  set_servo(pie_ad_der, 90); delay(10);
  set_servo(pie_atr_der, 90); delay(10);
  set_servo(pie_atr_izq, 90); delay(10);
  
  delay(1000);
}
//----------------------------


//----- Position rest -----
void pos_rest(){

  set_servo(femur_ad_izq, 150); delay(10);
  set_servo(femur_ad_der, 30); delay(10);
  set_servo(femur_atr_der, 150); delay(10);
  set_servo(femur_atr_izq, 30); delay(10);
  
  set_servo(pie_ad_izq, 150); delay(10);
  set_servo(pie_ad_der, 50); delay(10);
  set_servo(pie_atr_der, 130); delay(10);
  set_servo(pie_atr_izq, 50); delay(10);
  
  delay(1000);
}
//-------------------------


//----- Position up -----
void pos_up(){

  set_servo(femur_ad_izq, 120); delay(20);
  set_servo(femur_ad_der, 50); delay(20);
  set_servo(femur_atr_der, 120); delay(20);
  set_servo(femur_atr_izq, 50); delay(20);
  
  set_servo(pie_ad_izq, 60); delay(20);
  set_servo(pie_ad_der, 120); delay(20);
  set_servo(pie_atr_der, 60); delay(20);
  set_servo(pie_atr_izq, 120); delay(20);
  
  delay(1000);

}
//---------------------------


//----- Función para pasar de pulsos a ángulos -----
void set_servo(int n_servo, int angle){
  
  //----- Pasamos los pulsos a ángulos -----
  int duty = map(angle, 0, 180, pos_0, pos_180);
  
  //(servo, pos_inicial_pulso, pos_final_pulso)
  servo.setPWM(n_servo, 0, duty); 
}
//--------------------------------------------------
