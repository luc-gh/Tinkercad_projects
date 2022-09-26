//definições para manipulação dos displays com 74HC595
#define dados 10        //entrada ou DS
#define passaDados 8    //ST_CP ou latch ou reg. de saída
#define deslocaDados 9  //SH_CP ou clock ou reg. de deslocamento

//Teclado
#include <Keypad.h>     //biblioteca do teclado
const byte LeC = 4;  //4 linhas e 4 colunas
char teclas[LeC][LeC] = { //símbolos de cada tecla
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte Linhas[LeC] = {7,6,5,4};  //pinos das linhas
byte Colunas[LeC] = {3,2,1,0}; //pinos das colunas
//inicialização e definição das teclas com o método 'Keypad' (teclado)
Keypad myKeypad = Keypad(makeKeymap(teclas), Linhas, Colunas, LeC, LeC);

byte digitos[16] = { //
  B11111100,  // = 0    			HEX: 0xFC
  B01100000,  // = 1    			HEX: 0x60
  B11011010,  // = 2    			HEX: 0xDA
  B11110010,  // = 3    			HEX: 0xF2
  B01100110,  // = 4    			HEX: 0x66
  B10110110,  // = 5    			HEX: 0xB6
  B10111110,  // = 6    			HEX: 0xBE
  B11100000,  // = 7    			HEX: 0xE0
  B11111110,  // = 8    			HEX: 0xFE
  B11100110,  // = 9    			HEX: 0xE6
  B00000001,  // = asterisco (DP)   HEX: 0x01
  B00000000,  // =      			HEX: 0x00
  B11101110,  // = A    			HEX: 0x77
  B00111110,  // = B    			HEX: 0x1f
  B10011100,  // = C    			HEX: 0x4e
  B01111010   // = D    			HEX: 0x3d
};

void setup(){
  pinMode(dados, OUTPUT);
  pinMode(passaDados, OUTPUT);
  pinMode(deslocaDados, OUTPUT);
}

void display(byte n){
  // coloca o pino de latch em nível baixo, antes de enviar os dados
  digitalWrite(passaDados, LOW);

  // envio da dados (no formato binário associado a sequência dos pinos)
  shiftOut(dados, deslocaDados, LSBFIRST, digitos[n]); // LSB: começa a ler os bits do pino de menor valor

  // coloca o pino de latch em nível alto, depois de enviar os dados
  digitalWrite(passaDados, HIGH);
}

void loop(){
  char Botao = myKeypad.getKey(); //Lê o teclado
  if(Botao){ //Verifica se o teclado foi pressionado (e entra no bloco de código se sim)
    switch(Botao){
      case '*':
      	display(10);
      	break;
      case '#':
      	display(11);
      	break;
      case 'A':
      	display(12);
      	break;
      case 'B':
      	display(13);
      	break;
      case 'C':
      	display(14);
      	break;
      case 'D':
      	display(15);
      	break;
      default:
      	display((int(Botao) - 48));
    }
  }
}
