//----- PINES MOTOR DERECHO -----
const byte IN1 = 5;
const byte IN2 = 6;
//-------------------------------


//----- PINES MOTOR IZQUIERDO -----
const byte IN3 = 7;
const byte IN4 = 8;
//---------------------------------


//----- PINES SENSOR ULTRASÓNICO -----
const byte trigg = 10;
const byte echo = 9;
//------------------------------------

const byte led = 13;

//----- DEFINICIÓN DE FUNCIONES -----
void adelante();
void atras();
void izquierda();
void derecha();
void detener();
void autonomo();
//-----------------------------------


void setup() {
  Serial.begin(9600);

  //----- MOTORES PARTE DERECHA -----
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  //----- MOTORES PARTE IZQUIERDA -----
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //----- SENSOR ULTRASÓNICO -----
  pinMode(trigg, OUTPUT);
  pinMode(echo, OUTPUT);
  digitalWrite(trigg, LOW);

  pinMode(led, OUTPUT);

}

void loop() {
  
  if (Serial.available() > 0){
    char data = Serial.read();

    //---------- CONTROL DE MOTORES ----------
    if (data == 'a'){
      adelante();

    }else if (data == 'b'){
      atras();
      
    }else if (data == 'c'){
      izquierda();
      
    }else if (data == 'd'){
      derecha();
      
    }else if (data == 'e'){
      detener();
    
    }else if (data == 'f'){
      autonomo();
    }
    //----------------------------------------
  }
}

//----- Función adelante -----
void adelante(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
//----------------------------


//----- Función retroceder -----
void atras(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
//------------------------------


//----- Función izquierda -----
void izquierda(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
//-----------------------------


//----- Función derecha -----
void derecha(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
//---------------------------


//----- Función stop -----
void detener(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
//------------------------


//----- Función autónomo -----
void autonomo(){

  //----- Pulso mínimo de 10ms -----
  digitalWrite(trigg, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigg, LOW);
  //--------------------------------

  long tiempo = pulseIn(echo, HIGH);
  int distancia = tiempo/58;
  delay(10);

  if (distancia <=15 && distancia >=5){
    digitalWrite(led, HIGH);

    detener();
    delay(200);

    atras();
    delay(500);

    izquierda();
    delay(500);

    digitalWrite(led, LOW);
    
  }else{
    adelante();
    
  }
}
//----------------------------
