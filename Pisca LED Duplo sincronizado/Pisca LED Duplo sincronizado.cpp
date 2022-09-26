// Código em C++

int LedVermelho = 13; //Cria uma variável que representará o pino 13
int LedVerde = 12;    //Cria uma variável que representará o pino 12

void setup(){
  pinMode(LedVermelho, OUTPUT); //Define pino 13 com SAÍDA (5V)
  pinMode(LedVerde, OUTPUT);    //Define pino 12 com SAÍDA (5V)
}

void loop()
{
  digitalWrite(LedVermelho, HIGH); //Acende o LED vermelho
  digitalWrite(LedVerde, HIGH);    //Acende o LED verrde
  delay(500); //Cria um atraso de 0.5s na execução
  digitalWrite(LedVermelho, LOW);  //Apaga o LED vermelho
  digitalWrite(LedVerde, LOW);     //Apaga o LED verde
  delay(600); //Cria um atraso de 0.6s na execução
}
