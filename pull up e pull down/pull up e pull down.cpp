#define LedAzul 8
#define BotaoAzul 9
#define LedVerde 11
#define BotaoVerde 10
void setup(){
  pinMode(LedAzul, OUTPUT);
  pinMode(BotaoAzul, INPUT);
  pinMode(LedVerde, OUTPUT);
  pinMode(BotaoVerde, INPUT);
}
void loop(){
  if(digitalRead(BotaoAzul) == LOW){
    for(int i = 0; i < 5; i++){
      digitalWrite(LedAzul, HIGH);
      delay(350);
      digitalWrite(LedAzul, LOW);
      delay(300);
    }
  }
  if(digitalRead(BotaoVerde) == HIGH){
    for(int i = 0; i < 5; i++){
      digitalWrite(LedVerde, HIGH);
      delay(350);
      digitalWrite(LedVerde, LOW);
      delay(300);
    }
  }
}
