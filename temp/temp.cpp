//LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
//Temperatura
float Stemp, temp;
//Relé
int rele = 9;
//LEDs
int verde = 10, vermelho = 11;
//SETUP
void setup(){
  DDRB = B00001111;
  //DDRD = B11111111;
  lcd.begin(16,2);
}
//LOOP
void loop(){
  Stemp = analogRead(A0);
  temp = map(Stemp, 20, 358, -40, 125);
  delay(70);

  if(temp < 25){
    digitalWrite(rele, LOW);
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, LOW);
    lcd.setCursor(0,0);
    lcd.print("Lampada acesa - Temp < 25 C");
    lcd.setCursor(0,1);
    lcd.print("Estufa em aquecimento ");
    for(int i=0;i<6;i++){lcd.scrollDisplayLeft();delay(55);}
  }
  else if((temp >= 25) && (temp < 50)){
    digitalWrite(rele, LOW);
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Temperatura estavel - lampada acesa ");
    lcd.setCursor(0,1);
    lcd.print("Estufa em aquecimento ");
    for(int i=0;i<6;i++){lcd.scrollDisplayLeft();delay(25);}
  }
  else{
    digitalWrite(rele, HIGH);
    digitalWrite(vermelho, HIGH);
    digitalWrite(verde, LOW);
    lcd.setCursor(0,0);
    lcd.print("Atencao! Temp > 50 C       ");
    lcd.setCursor(0,1);
    lcd.print("Estufa quente         ");
    for(int i=0;i<6;i++){lcd.scrollDisplayLeft();delay(25);}
  }
}
