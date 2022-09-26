#define LED 8
#define Botao 9
void setup(){
  pinMode(LED, OUTPUT);
  pinMode(Botao, INPUT);
  Serial.begin(9600);
}
void loop(){
  if(digitalRead(Botao) == HIGH){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  Serial.println(digitalRead(Botao));
}
