/*--------------------------------------------------------------------
   ROBO SEGUINDO A LINHA BRANCA (CONTROLADOR DOS DIVRES DOS MOTORES)
   CENTRO DE CONTROLE (MOVIMENTO DO ROBÔ)

   -------------------------------------------------------------------*/
// Declarações para drivers
// Declarações para drivers
const int steppin1 = 6;
//const int steppin2 = 7;
const int dirpin1 = 7;
//const int dirpin2 = 6;


//Variável para o controle do loop for
int x = 0;


void setup() {
  Serial.begin(9600);

  //Declaração de IO, pulso dos dois motores, e a direção dos dois motores
  pinMode(steppin1, OUTPUT);
  //pinMode(steppin2, OUTPUT);
  pinMode(dirpin1, OUTPUT);
  //pinMode(dirpin2, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) {

    x = Serial.read();

    if(x == 'A'){
      digitalWrite(dirpin1, HIGH);
      //digitalWrite(dirpin2, HIGH);
      delay(1);
      
      for (x = 0; x < 100; x++) {
        digitalWrite(steppin1, HIGH);
        //digitalWrite(steppin2, LOW);
        delayMicroseconds(2000);
        digitalWrite(steppin1, LOW);
        //digitalWrite(steppin2, HIGH);
        delayMicroseconds(2000);
        Serial.println("Horario");
       }
    }
    if( x == 'B'){
      digitalWrite(dirpin1, LOW);
      //digitalWrite(dirpin2, LOW);
      
      delay(1);
      for (x = 0; x < 100; x++) {
        digitalWrite(steppin1, HIGH);
        //digitalWrite(steppin2, HIGH);
        delayMicroseconds(2000);
        digitalWrite(steppin1, LOW);
        //digitalWrite(steppin2, LOW);
        delayMicroseconds(2000);
        Serial.println("Anti");
    }
  }
 }
}
