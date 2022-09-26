//Serial.print(teclado[i]);  //traduz o índice do valor lido para o atual valor (nome) da chave

//Displays (da esquerda para a direita)
#define d1 8   //primeiro
#define d2 9   //segundo
#define d3 10  //terceiro
#define d4 11  //quarto

//Valores de cada tecla
byte digitos[16] = { //central, sup-esq, inf-esq, baixo, inf-dir, sup-dir, cima, indiferente (pino 0)
  B00001100,  //1    byte 0
  B10110110,  //2
  B10011110,  //3
  B11101110,  //A
  B11001100,  //4
  B11011010,  //5    byte 5
  B11111010,  //6
  B11111000,  //b
  B00001110,  //7    byte 8
  B11111110,  //8
  B11011110,  //9
  B01110010,  //C    byte 11
  B00000001,  //*
  B01111110,  //0
  B11101100,  //# (Coloquei como se fosse o H)
  B10111100   //d
};

//TECLADO
//Limiares[]: valores de tensão lidos pelo arduino a partir da associação de resistores que conecta linhas e colunas 
//Teclado[]: valores das teclas em sequência, considerando tanto a ordem no teclado quanto a ordem dos limiares
int limiares[16] = {930, 912, 894, 877, 852, 837, 822, 808, 787, 774, 761, 749, 731, 719, 708, 698};
//char teclado[16]={'1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0', '#', 'D'};

void piscaPisca(int click, byte a, byte b, byte c, byte d){ //mantém os displays acesos mutualmente e com cada valor correspondente
  PORTD = digitos[a];
  digitalWrite(d1, LOW);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
  delay(10);
  if(click > 0){
    PORTD = digitos[b];
    digitalWrite(d1, HIGH);
    digitalWrite(d2, LOW);
    digitalWrite(d3, HIGH);
    digitalWrite(d4, HIGH);
    delay(10);
    if(click > 1){
      PORTD = digitos[c];
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, LOW);
      digitalWrite(d4, HIGH);
      delay(10);
      if(click > 2){
        PORTD = digitos[d];
        digitalWrite(d1, HIGH);
        digitalWrite(d2, HIGH);
        digitalWrite(d3, HIGH);
        digitalWrite(d4, LOW);
        testeSenha(a,b,c,d);
      }
    }
  }
}

void testeSenha(byte f, byte g, byte h, byte i){
  if((f == 5) && (g == 8) && (h == 0) && (i == 11)){ //571C
    digitalWrite(12, HIGH);  //senha correta
    delay(10);
    digitalWrite(12, LOW);
    delay(10);
    digitalWrite(12, HIGH);
    delay(10);
    digitalWrite(12, LOW);
    delay(10);
  }
  else{						 //senha incorreta
    digitalWrite(13, HIGH);
    delay(10);
    digitalWrite(13, LOW);
    delay(10);
    digitalWrite(13, HIGH);
    delay(10);
    digitalWrite(13, LOW);
    delay(10);
  }
}

void setup(){ 
  DDRB = B00111111;
  DDRD = B11111111;
  pinMode(A0, INPUT);
}

void loop(){ 
  int numeroClick = 0;
  byte v1 = 15, v2 = 15, v3 = 15, v4 = 15;
  
  
  while(numeroClick < 4){
    int valor = analogRead(A0);
    if(valor > 1000){
	  
    }
    for (int i = 0; i < 16; i++){
      //O valor de A0 é próximo o suficiente de um dos valores do teclado?
      if (abs(valor - limiares[i]) < 5){ //5 é um valor de unidades suficiente para abranger a leitura correta
        while (analogRead(A0) > 0){
          delay(25);
        }
        while(analogRead(A0) == 0){
          switch(numeroClick){
            case 0:
              v1 = i;
              piscaPisca(numeroClick, v1, 0, 0, 0);
              break;
            case 1:
              v2 = i;
              piscaPisca(numeroClick, v1, v2, 0, 0);
              break;
            case 2:
              v3 = i;
              piscaPisca(numeroClick, v1, v2, v3, 0);
              break;
            case 3:
              v4 = i;
              piscaPisca(numeroClick, v1, v2, v3, v4);
              break;
            default:
              break;
          }
        }
        numeroClick++;
      }
    }
  }
}
