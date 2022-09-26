// Código em C++

int LedVermelho = 13; //Cria uma variável que representará o pino 13
int LedVerde = 11;    //Cria uma variável que representará o pino 12
int LedAmarelo = 12;  //Cria uma variável que representará o pino 11

void setup(){
  pinMode(LedVermelho, OUTPUT); //Define pino 13 com SAÍDA (5V)
  pinMode(LedVerde, OUTPUT);    //Define pino 12 com SAÍDA (5V)
  pinMode(LedAmarelo, OUTPUT);  //Define pino 11 com SAÍDA (5V)
}

void loop()
{
  digitalWrite(LedVerde, HIGH);    //Acende o LED verde
  delay(1500); //Cria um atraso de 1.5s na execução
  digitalWrite(LedVerde, LOW);     //Apaga o LED verde
  digitalWrite(LedAmarelo, HIGH);  //Acende o LED amarelo
  delay(650); //Cria um atraso de 0.65s na execução
  digitalWrite(LedAmarelo, LOW); //Apaga o LED amarelo
  digitalWrite(LedVermelho, HIGH); //Acende o LED vermelho
  delay(1700); //Cria um atraso de 1.7s na execução
  digitalWrite(LedVermelho, LOW);  //Apaga o LED vermelho
}
