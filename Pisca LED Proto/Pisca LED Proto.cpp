// Código em C++ 

//As funções setup e loop são funções obrigatórias

// Esse código não foi aplicado numa IDE de C++, logo, 
// as especificações dele podem mudar de acordo com a estrutura de projeto.

void setup() //função de definições ou configurações
{
  pinMode(13, OUTPUT); //define o pino 13 (digital) como saída
}

void loop()  //função de repetição
{
  digitalWrite(13, HIGH); //coloca o pino 13 com valor alto (1)
  delay(400); // Atrasa a execução em 400 milisegundos (0.4s)
  digitalWrite(13, LOW);  //coloca o pino 13 com valor baixo (0)
  delay(400); // Atrasa a execução em 400 milisegundos (0.4s)
}

