/*--------------------------------------------------------------------
   ROBO SEGUINDO A LINHA BRANCA (CONTROLADOR DOS DIVRES DOS MOTORES) + SENSORES DA LINA
   CENTRO DE CONTROLE (MOVIMENTO DO ROBÔ)

   -------------------------------------------------------------------*/
//***5 Channel IR Sensor Connection***//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4

// Declarações para drivers
const int steppin1 = 9;
const int steppin2 = 8;
const int dirpin1 = 7;
const int dirpin2 = 6;

int serialInput = 0;

//Variável para o controle do loop for
int x = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo informações dos sensores");

  //Declarando as entradas dos sensores seguidor de linhas
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);

  //Declaração de IO, pulso dos dois motores, e a direção dos dois motores
  pinMode(steppin1, OUTPUT);
  pinMode(steppin2, OUTPUT);
  pinMode(dirpin1, OUTPUT);
  pinMode(dirpin2, OUTPUT);
}

void loop() {

  //Leitura sensores
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor

  //Variável última posição
  int s1Ant = digitalRead(ir1);  //Left Most Sensor
  int s2Ant = digitalRead(ir2);  //Left Sensor
  int s3Ant = digitalRead(ir3);  //Middle Sensor
  int s4Ant = digitalRead(ir4);  //Right Sensor
  int s5Ant = digitalRead(ir5);  //Right Most Sensor
  
  //Serial.println("S1 S2 S3 S4 S5");
  Serial.print(s1);
  Serial.print("  ");
  Serial.print(s2);
  Serial.print("  ");
  Serial.print(s3);
  Serial.print("  ");
  Serial.print(s4);
  Serial.print("  ");
  Serial.print(s5);
  Serial.println(" ");
  
  
  //Fazendo com que o robo ande, dependendo do controlador que estiver ativado
  serialInput = Serial.read();
  
  if (s3 == 0)
  {
    Serial.println("Frente");
    moveForward();
    delay(10);
  }

  else if (s4 == 0 || s5 == 0)
  {
    Serial.println("Direita");
    turnRight();
    delay(200);
  }

  else if (s2 == 0 || s1 == 0)
  {
    Serial.println("Esquerda");
    turnLeft();
    delay(200);
  }
  else (s1 == 0 && s2 == 0 && s3 == 0 s4 == 0 && s5 == 0){
    
  
  }
}

/*--------------------------------------------------------------------
   FUNÇÔES PARA FAZER O ROBO SE MOVER EM DIVERSAS DIREÇOES

   -------------------------------------------------------------------*/

//FUNÇÃO PARA ANDAR PARA A FRENTE
void moveForward()
{
  
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, HIGH);
  digitalWrite(dirpin2, LOW);
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for (x = 0; x < 100; x++) {
    digitalWrite(steppin1, HIGH);
    digitalWrite(steppin2, HIGH);
    delayMicroseconds(3000);
    digitalWrite(steppin1, LOW);
    digitalWrite(steppin2, LOW);
    delayMicroseconds(3000);
  }
  
}

//FUNÇÃO PARA VIRAR A DIREITA
void turnRight()
{
  
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, LOW);
  digitalWrite(dirpin2, LOW);
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for (x = 0; x < 25; x++) {
    digitalWrite(steppin1, HIGH);
    digitalWrite(steppin2, HIGH);
    delayMicroseconds(6000);
    digitalWrite(steppin1, LOW);
    digitalWrite(steppin2, LOW);
    delayMicroseconds(6000);
  }
  
}

//FUNÇÃO PARA VIRAR A ESQUERDA
void turnLeft()
{
  
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, HIGH);
  digitalWrite(dirpin2, HIGH);
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for (x = 0; x < 25; x++) {
    digitalWrite(steppin1, HIGH);
    digitalWrite(steppin2, HIGH);
    delayMicroseconds(6000);
    digitalWrite(steppin1, LOW);
    digitalWrite(steppin2, LOW);
    delayMicroseconds(6000);
  }
  
}
