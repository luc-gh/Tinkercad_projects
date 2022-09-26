//pinos de entrada
#define centena 9
#define dezena 8
#define unidade 12
#define contR 10 
#define contP 11

//variáveis
int valor = 0, cent, dez, uni, condicao;

//vetor dos números
int numeros[10]={0x3F,0x06,0xDB,0xCF,0xE6,0xED,0xFD,0x07,0xFF,0xEF};

//função que alterna o acionamento dos displays
void piscaPisca(){
  
  digitalWrite(centena, HIGH); 
  digitalWrite(dezena, HIGH); 
  digitalWrite(unidade, LOW);//unidade
  PORTD = numeros[uni];
  delay(10);
  
  digitalWrite(centena, HIGH);
  digitalWrite(dezena, LOW); //dezena
  digitalWrite(unidade, HIGH);
  PORTD = numeros[dez];
  delay(10);
  
  digitalWrite(centena, LOW);//CENTENA
  digitalWrite(dezena, HIGH); 
  digitalWrite(unidade, HIGH);
  PORTD = numeros[cent];
  delay(10);
}

//função de configurações
void setup(){
  DDRB = B11010011; //pinos de entrada (4)
  DDRD = B11111111; //pinos de saída (7)
  //Serial.begin(9600);
}

//função de repetição
void loop(){
  //atribuições para o estado inicial (EI) dos displays (00)
  digitalWrite(unidade, LOW);
  digitalWrite(dezena, LOW);
  digitalWrite(dezena, LOW);
  PORTD = numeros[valor];
  //Serial.print(valor);
  condicao = 0;
  
  //laço que estabiliza o EI
  while(condicao == 0){
    //laço que ocorre com o acionamento do 1º botão (incremento)
    while(digitalRead(contP) == HIGH){
	  valor++;
      if(valor > 999){
        valor = 999;
      }
	      
      cent= valor/100; //350/100=3
      dez = (valor%100)/10; //resto= 50/10 = 5 
      uni = valor%10;//350%10 = resto=0
      
      piscaPisca();
      continue; //mantém a repetição do laço
    }
    
    //laço que ocorre com o acionamento do 2º botão (decremento)
    while(digitalRead(contR) == HIGH){
      valor--;
      if(valor < 0){
        valor = 0;
        condicao = 1; //quebra o laço para estabilizar o EI
      }
    
      cent= valor/100; //350/100=3
      dez = (valor%100)/10; //resto= 50/10 = 5 
      uni = valor%10;
      
      piscaPisca();
      continue; //mantém a repetição do laço
    }
    
    //laço que ocorre se nenhum botão estiver sendo acionado
    while((digitalRead(contP) == LOW) && (digitalRead(contR) == LOW)){
	  piscaPisca(); //apenas mantém os displays piscando
      continue; //mantém a repetição do laço
    }
  }
}
