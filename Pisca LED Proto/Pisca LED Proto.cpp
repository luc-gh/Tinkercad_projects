// C�digo em C++ 

//As fun��es setup e loop s�o fun��es obrigat�rias

// Esse c�digo n�o foi aplicado numa IDE de C++, logo, 
// as especifica��es dele podem mudar de acordo com a estrutura de projeto.

void setup() //fun��o de defini��es ou configura��es
{
  pinMode(13, OUTPUT); //define o pino 13 (digital) como sa�da
}

void loop()  //fun��o de repeti��o
{
  digitalWrite(13, HIGH); //coloca o pino 13 com valor alto (1)
  delay(400); // Atrasa a execu��o em 400 milisegundos (0.4s)
  digitalWrite(13, LOW);  //coloca o pino 13 com valor baixo (0)
  delay(400); // Atrasa a execu��o em 400 milisegundos (0.4s)
}

