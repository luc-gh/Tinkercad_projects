#define BotProg 11
#define BotRegr 10
int contagem=0;
//gfedcba
//6543210
//central,sup-esq,inf-esq,baixo,inf-dir,sup-dir,cima
byte numeros[10]{
  B00111111, //0
  B00000110, //1
  B11011011, //2
  B11001111, //3
  B11100110, //4
  B11101101, //5
  B11111101, //6
  B00000111, //7
  B11111111, //8
  B11101111  //9
};

void setup(){
  DDRB = B00000000; //8 a 13 entradas
  DDRD = B11111111; //0 a 7 saídas
}

void loop(){
  contagem = 0;
  PORTD = numeros[contagem];
  while(digitalRead(BotRegr) == LOW){
    if(digitalRead(BotProg) == HIGH){
      contagem++;
      if(contagem > 9){
        contagem = 9;
      }
      PORTD = numeros[contagem];
      delay(100);
    }
  }
  for(int i = contagem; i > -1; i--){
    delay(1000);
    PORTD = numeros[i];
  }
}
