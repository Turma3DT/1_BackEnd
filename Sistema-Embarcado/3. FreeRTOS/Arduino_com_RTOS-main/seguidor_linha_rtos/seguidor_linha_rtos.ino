#include <Arduino_FreeRTOS.h>
 
// Declaraçôes para os enviar para centro de controle
 bool controller_moveForward = LOW;
 bool controller_moveBack = LOW;
 bool controller_turnRight = LOW;
 bool controller_turnLeft = LOW;
 
//Declarações para sensor seguidor de linha
const int pinoQRE1 = A0;
const int pinoQRE2 = A2;
const int pinoQRE3 = A3;
const int pinoQRE4 = A4;
const int pinoQRE5 = A5;
const int pinoQRE6 = A6;
const int pinoQRE7 = A7;// Arduino Mega
const int pinoQRE8 = A8;// Arduino Mega
 
String direcao = "u";
 
const int range_sensor = 750;
 
//-------------------------------------------------- \\
// Declarações para drivers
const int steppin1 = 7;
const int steppin2 = 9;
const int dirpin1 = 13;
const int dirpin2 = 11;
// ------------------------------------------------------ \\
 
//Variável para o controle do loop
int x = 0;
 
//Tasks
TaskHandle_t lineHandle;
TaskHandle_t stopHandle;
TaskHandle_t driverHandle; 
 
void setup() {
 //Inicializa Serial
 Serial.begin(9600);
 
 //Declarando as entradas dos sensores seguidor de linhas
  pinMode(pinoQRE1, INPUT);
  pinMode(pinoQRE2, INPUT);
  pinMode(pinoQRE3, INPUT);
  pinMode(pinoQRE4, INPUT);
  pinMode(pinoQRE5, INPUT);
  pinMode(pinoQRE6, INPUT);
  pinMode(pinoQRE7, INPUT);
  pinMode(pinoQRE8, INPUT);
 
 //Declaração de IO, pulso dos dois motores, e a direção dos dois motores
 pinMode(steppin1, OUTPUT);
 pinMode(steppin2, OUTPUT);
 pinMode(dirpin1, OUTPUT);
 pinMode(dirpin2, OUTPUT);
 
 //Cria tarefa lineAGVTask
xTaskCreate(lineAGVTask, //Funcao
 "Task1", //Nome
 100, //Pilha
 NULL, //Parametro
 1, //Prioridade
 &lineHandle);
 
 //Cria tarefa driverAGVTask
 xTaskCreate(driverAGVTask,
 "Task2",
 100,
 NULL,
 1,
 &driverHandle); 
 
 /* //Cria tarefa stopAGVTask
 xTaskCreate(stopAGVTask,
 "Task3",
 100,
 NULL,
 1,
 &stopHandle); 
 */ 
 
}
 
void loop() {
 // Nada é feito aqui, Todas as funções são feitas em Tasks
}
 
//FUNÇÃO PARA ANDAR PARA A FRENTE
void moveForward()
{
 //Setando a direção de rotação de cada motor
 digitalWrite(dirpin1, LOW);
 digitalWrite(dirpin2, HIGH);
 
 //Mandando os pulsos para o driver mover os motores
 for(x = 0; x < 100; x++) {
 digitalWrite(steppin1, HIGH);
 digitalWrite(steppin2, HIGH);
 delayMicroseconds(1700);
 digitalWrite(steppin1, LOW);
 digitalWrite(steppin2, LOW);
 delayMicroseconds(2000);
 } 
}
 
//FUNÇÃO PARA ANDAR PARA A TRÀS
void moveBack()
{
 //Setando a direção de rotação de cada motor
 digitalWrite(dirpin1, HIGH);
 digitalWrite(dirpin2, LOW);
 
 //Mandando os pulsos para o driver mover os motores
 for(x = 0; x < 100; x++) {
 digitalWrite(steppin1, HIGH);
 digitalWrite(steppin2, HIGH);
 delayMicroseconds(1700);
 digitalWrite(steppin1, LOW);
 digitalWrite(steppin2, LOW);
 delayMicroseconds(1700);
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
 for(x = 0; x < 10; x++) {
 digitalWrite(steppin1, HIGH);
 digitalWrite(steppin2, HIGH);
 delayMicroseconds(1700);
 digitalWrite(steppin1, LOW);
 digitalWrite(steppin2, LOW);
 delayMicroseconds(1700);
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
 for(x = 0; x < 10; x++) {
 digitalWrite(steppin1, HIGH);
 digitalWrite(steppin2, HIGH);
 delayMicroseconds(1700);
 digitalWrite(steppin1, LOW);
 digitalWrite(steppin2, LOW);
 delayMicroseconds(1700);
 }
}
 
 
void lineAGVTask (void *param) {
 
 (void) param;
 
 while(1){
 // Se todos os sensores centrais, conseguirem detectar a linha, e a variavel de controle false, então mover o robo para frente
 if ( analogRead(pinoQRE1) < range_sensor && analogRead(pinoQRE8) < range_sensor && analogRead(pinoQRE2) > range_sensor && analogRead(pinoQRE3) > range_sensor && analogRead(pinoQRE4) > range_sensor & analogRead(pinoQRE5) > range_sensor && analogRead(pinoQRE6) > range_sensor && analogRead(pinoQRE8) > range_sensor)
 {
 //Manda para os controladores para qualquer outro comando nos drivers dos motores
 //----
 controller_moveBack = LOW ;
 controller_turnRight = LOW ;
 controller_turnLeft = LOW ;
 //---
 controller_moveForward = HIGH; //Mover para frente
 direcao = "f";
 }
 
 // Se um dos sensores da esquerda indentificar a linha, então firar para a direita
 if ( analogRead(pinoQRE1) < range_sensor && analogRead(pinoQRE8) > range_sensor && analogRead(pinoQRE2) < range_sensor && analogRead(pinoQRE3) > range_sensor && analogRead(pinoQRE4) > range_sensor & analogRead(pinoQRE5) > range_sensor && analogRead(pinoQRE6) > range_sensor && analogRead(pinoQRE7) > range_sensor )
 {
 //Manda para os controladores para qualquer outro comando nos drivers dos motores
 //----
 controller_moveBack = LOW ;
 controller_moveForward = LOW ;
 controller_turnRight =  LOW ;
 //---
 controller_turnLeft = HIGH; //Virar para Esquerda
 direcao = "e";
 }
 
 if (analogRead(pinoQRE1) > range_sensor && analogRead(pinoQRE8) < range_sensor && analogRead(pinoQRE2) > range_sensor && analogRead(pinoQRE3) > range_sensor && analogRead(pinoQRE4) > range_sensor & analogRead(pinoQRE5) > range_sensor && analogRead(pinoQRE6) > range_sensor && analogRead(pinoQRE7) < range_sensor)
 {
 //Manda para os controladores para qualquer outro comando nos drivers dos motores
 //----
 controller_moveBack = LOW ;
 controller_moveForward = LOW ;
 controller_turnLeft =  LOW ;
 //---
 controller_turnRight = HIGH; //Virar para Direita
 direcao = "d";
 }
 Serial.print("Task1");
 delay(500);
 
 }
}
 
 
void driverAGVTask (void *param) {
 
 (void) param;
 
 while(1){
 
 //Fazendo com que o robo ande, dependendo do controlador que estiver ativado
 while(true)
 {
  //Setando a direção de rotação de cada motor
 digitalWrite(dirpin1, LOW);
 digitalWrite(dirpin2, HIGH);
 }
 
 //Mandando os pulsos para o driver mover os motores
 for(x = 0; x < 100; x++) {
 digitalWrite(steppin1, HIGH);
 digitalWrite(steppin2, HIGH);
 delayMicroseconds(1000);
 digitalWrite(steppin1, LOW);
 digitalWrite(steppin2, LOW);
 delayMicroseconds(1000);
 }
 if( controller_moveForward == HIGH )
 {
 moveForward();
 Serial.println("FRENTE");
 }
 
 if( controller_moveBack == HIGH )
 {
 moveBack();
 Serial.println("TRAS");
 }
 
 if (controller_turnRight == HIGH)
 {
 turnRight();
 delay(500);
 Serial.println("DIREITA");
 }
 
 if (controller_turnLeft == HIGH)
 {
 turnLeft();
 delay(500);
 Serial.println("ESQUERDA");
 } 
 
 }
}
