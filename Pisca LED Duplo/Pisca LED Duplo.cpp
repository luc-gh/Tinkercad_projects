// C�digo em C++

int LedVermelho = 13; //Cria uma vari�vel que representar� o pino 13
int LedVerde = 12;    //Cria uma vari�vel que representar� o pino 12

void setup(){
  pinMode(LedVermelho, OUTPUT); //Define pino 13 com SA�DA (5V)
  pinMode(LedVerde, OUTPUT);    //Define pino 12 com SA�DA (5V)
}

void loop()
{
  digitalWrite(LedVermelho, HIGH); //Acende o LED vermelho
  delay(200); //Cria um atraso de 0.2s na execu��o
  digitalWrite(LedVerde, HIGH);    //Acende o LED verrde
  delay(700); //Cria um atraso de 0.7s na execu��o
  digitalWrite(LedVermelho, LOW);  //Apaga o LED vermelho
  delay(300); //Cria um atraso de 0.3s na execu��o
  digitalWrite(LedVerde, LOW);     //Apaga o LED verde
  delay(800); //Cria um atraso de 0.8s na execu��o
}
