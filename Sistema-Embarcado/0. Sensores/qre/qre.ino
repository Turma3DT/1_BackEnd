 
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
 

void setup() {
  // put your setup code here, to run once:

   //Declarando as entradas dos sensores seguidor de linhas
  pinMode(pinoQRE1, INPUT);
  pinMode(pinoQRE2, INPUT);
  pinMode(pinoQRE3, INPUT);
  pinMode(pinoQRE4, INPUT);
  pinMode(pinoQRE5, INPUT);
  pinMode(pinoQRE6, INPUT);
  pinMode(pinoQRE7, INPUT);
  pinMode(pinoQRE8, INPUT);

  Serial.begin(9600);
  Serial.println("Lendo dados dos sensores");

}

void loop() {
 
 Serial.print("QRE1 - ");
 Serial.println(analogRead(pinoQRE1));
 // Serial.print("QRE2 - ");
 // Serial.println(analogRead(pinoQRE2));
   //Serial.print("QRE3 - ");
  //Serial.println(analogRead(pinoQRE3));
   //Serial.print("QRE4 - ");
  //Serial.println(analogRead(pinoQRE4));
   //Serial.print("QRE5 - ");
  //Serial.println(analogRead(pinoQRE5));
   //Serial.print("QRE6 - ");
  //Serial.println(analogRead(pinoQRE6));
   //Serial.print("QRE7 - ");
  //Serial.println(analogRead(pinoQRE7));
   //Serial.print("QRE8 - ");
  //Serial.println(analogRead(pinoQRE8));
  //Serial.println("---------------------------------------------");
 delay(1000);

}
