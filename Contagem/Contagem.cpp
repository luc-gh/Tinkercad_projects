//CONTAGEM

#define BotProg 13
#define BotRegr 12
int contagem = 0;
//B-agfedcb
//B-(central,sup-esq,inf-esq,baixo,inf-dir,sup-dir,cima)
byte numeros[10]{
  B10111111, //0
  B00000110, //1
  B11011011, //2
  B11001111, //3
  B01100110, //4
  B11101101, //5
  B11111101, //6
  B10000111, //7
  B11111111, //8
  B11101111  //9
};

void setup(){
  DDRB = B11001111; //Pino 12 e 13 entradas (comandos dos botões)
  DDRD = B11111111; //Pinos 0 a 7 são saídas
  Serial.begin(9600);
}

void loop(){
  PORTD = B00000000;
  if(digitalRead(BotProg == HIGH)){
    contagem++;
    if(contagem > 9){
      contagem = 0;
      
    }
    
  }
}
