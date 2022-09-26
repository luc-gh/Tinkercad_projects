//TECLADO
//Limiares[]: valores de tensão lidos pelo arduino a partir da associação de resistores que conecta linhas e colunas 
//Teclado[]: valores das teclas em sequência, considerando tanto a ordem no teclado quanto a ordem dos limiares
int limiares[16] = {930, 912, 894, 877, 852, 837, 822, 808, 787, 774, 761, 749, 731, 719, 708, 698};
char teclado[16] = {'1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0', '#', 'D'};

//LCD
#include <LiquidCrystal.h>           //biblioteca de LCD
LiquidCrystal lcd(8,9,10,11,12,13);  //inicialização do lcd

//RELÉ
#define rele 2

int valor;                           //valor de tensão lido no pino A0
char senha[4] = {'4','D','0','6'};   //senha correta
char digitos[4];                     //vetor que recebe os caracteres das teclas pressionadas

void setup(){ 
  DDRB = B00111111;
  DDRD = B11111111;
  pinMode(A0, INPUT);
  lcd.begin(16,2);
}

void display(char c, int x){ //imprime '*' no LCD a cada digito pressionado
  lcd.setCursor(x,1);
  lcd.print("*");
  digitos[x] = c;
}

void verificaSenha(char x[]){  //verifica se os digitos pressionados correspondem a senha correta
  delay(100);
  lcd.clear();
  lcd.print("VERIFICANDO...");
  lcd.blink();
  delay(500);
  if((x[0] == senha[0]) && (x[1] == senha[1]) && (x[2] == senha[2]) && (x[3] == senha[3])){
    lcd.clear();
    lcd.print("Senha correta!");
    digitalWrite(rele, HIGH);
    delay(500);
  }
  else{
    lcd.clear();
    lcd.print("Senha incorreta!");
    delay(500);
  }
  lcd.noBlink();
  delay(200);
}

int x = 0;  //variável que armazenará o número de clicks
void loop(){ 
  //estados iniciais
  lcd.setCursor(0,0);
  digitalWrite(rele, LOW);
  
  //inicio
  lcd.print("Digite a senha:");  //imprime no LCD
  valor = analogRead(A0);        //Lê o pino A0, verificando se o teclado foi pressionado
  if(valor > 0){
    delay(39);  //delay de sensibilidade
    for (int i = 0; i < 16; i++){
      //O valor de A0 é próximo o suficiente de um dos valores do teclado?
      if (abs(valor - limiares[i]) < 5){ //5 é um valor de unidades suficiente para abranger a leitura correta
        display(teclado[i], x); //de acordo com o valor de tecla e do nº de clicks no teclado, aciona a função que imprime cada digito pressionado no display
      }
    }
    if(x < 3){  //condição que repete a leitura do teclado por 4 vezes (para que a senha tenha 4 dígitos)
      x++;
    }
    else{
      x = 0;   //quando x = 3, já ocorreram 4 clicks no teclado
      verificaSenha(digitos); //então a função de verificação de senha é chamada
      lcd.clear();
    }    
  }
}
