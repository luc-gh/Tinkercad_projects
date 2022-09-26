//L293D - Ponte H - Entradas
const int motorDir1 = 10;   //pino 2 do L293D - GND do motor da esquerda
const int motorDir2 = A1;  //pino 7 do L293D - Vcc do motor da esquerda
const int motorEsq3 = 11;  //pino 10 do L293D - GND do motor da direita
const int motorEsq4 = A0;  //pino 15 do L293D - Vcc do motor da direita

//LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

//SENSOR ULTRASSONICO
#define trigger 13
#define echo 12

void setup(){
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motorDir1, OUTPUT);
  pinMode(motorEsq3, OUTPUT);
  pinMode(motorDir2, OUTPUT);
  pinMode(motorEsq4, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

float ultra(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(0005);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(0010);
  digitalWrite(trigger, LOW);
  float tempo = pulseIn(echo, HIGH);
  
  float cm = (tempo/2) / 29.1;
  return cm;
}

void motores(float d){
  lcd.setCursor(0,1);
  lcd.print("Comando:");
  lcd.setCursor(9,1);
  if(d < 80){
    lcd.print("Recuar   ");
    //Motor da direita -
    digitalWrite(motorDir1, HIGH); 
    analogWrite(motorDir2, 0);
    //Motor da esquerda -
    digitalWrite(motorEsq3, HIGH); 
    analogWrite(motorEsq4, 0);
    delay(3);
  }
  else if((d >= 80) && (d < 120)){
    lcd.print("Parar   ");
    //Motores parados
    digitalWrite(motorDir1, LOW); 
    analogWrite(motorDir2, 0);
    digitalWrite(motorEsq3, LOW); 
    analogWrite(motorEsq4, 0);
    delay(3);
  }
  else{
    lcd.print("Seguir  ");
    //Motor da direita +
    digitalWrite(motorDir1, LOW); 
    analogWrite(motorDir2, 255);
    //Motor da esquerda +
    digitalWrite(motorEsq3, LOW); 
    analogWrite(motorEsq4, 255);
    delay(3);
  }
}

void loop(){
  lcd.setCursor(0,0); 
  float dist = ultra();
  lcd.print("Distancia:");
  lcd.setCursor(11, 0);
  lcd.print(dist);
  motores(dist);
}
