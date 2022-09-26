void setup()
{
  DDRB = B11111111;
  DDRD = B11111111;
}

void loop()
{
  for(int i = 0; i < 3; i++){
    PORTB = B11010101; //Os 2 primeiros pinos são irrrelevantes
    PORTD = B10101010; //O ultimo pino é desconsiderável
    delay(1000);
    PORTB = B11101010; //Os 2 primeiros pinos são irrrelevantes
    PORTD = B01010100; //O ultimo pino é desconsiderável
    delay(1000);
  }
  for(int j = 0; j < 3; j++){
    PORTB = B00111111; //Os 2 primeiros pinos são irrrelevantes
    PORTD = B00000000; //O ultimo pino é desconsiderável
    delay(1000);
    PORTB = B00000000; //Os 2 primeiros pinos são irrrelevantes
    PORTD = B11111110; //O ultimo pino é desconsiderável
    delay(1000);
  }
}
