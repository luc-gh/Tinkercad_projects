/*byte digitos[16] = { //
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
};*/

//LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);

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


void setup(){
  lcd.begin(16,2);
}

char x = ' ';;
void display(char digito){
  lcd.print(digito);
}

void loop(){
  char Botao = myKeypad.getKey(); //Lê o teclado
  lcd.setCursor(0,0);
  if(Botao){ //Verifica se o teclado foi pressionado (e entra no bloco de código se sim)
    switch(Botao){
      case '*':
      	display('*');
      	break;
      case '#':
      	display('#');
      	break;
      case 'A':
      	display('A');
      	break;
      case 'B':
      	display('B');
      	break;
      case 'C':
      	display('C');
      	break;
      case 'D':
      	display('D');
      	break;
      default:
      	display((char(Botao)));
    }
  }
}
