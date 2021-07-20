const int pinoQRE1 = A0;
const int pinoQRE2 = A2;
const int pinoQRE3 = A3;
const int pinoQRE4 = A4;
const int pinoQRE5 = A5;
const int pinoQRE6 = A6;
const int pinoQRE7 = A7;// Arduino Mega
const int pinoQRE8 = A8;// Arduino Mega

void setup(){
  Serial.begin(9600);
  pinMode(pinoQRE1, INPUT);
  pinMode(pinoQRE2, INPUT);
  pinMode(pinoQRE3, INPUT);
  pinMode(pinoQRE4, INPUT);
  pinMode(pinoQRE5, INPUT);
  pinMode(pinoQRE6, INPUT);
  pinMode(pinoQRE7, INPUT);
  pinMode(pinoQRE8, INPUT);
  }

void loop(){
  int QRE_Value1 = analogRead(pinoQRE1);
  int QRE_Value2 = analogRead(pinoQRE2);
  int QRE_Value3 = analogRead(pinoQRE3);
  int QRE_Value4 = analogRead(pinoQRE4);
  int QRE_Value5 = analogRead(pinoQRE5);
  int QRE_Value6 = analogRead(pinoQRE6);
  int QRE_Value7 = analogRead(pinoQRE7);
  int QRE_Value8 = analogRead(pinoQRE8);
  //int mediaQRE = (QRE_Value1 + QRE_Value2 + QRE_Value3 + QRE_Value4 + QRE_Value5 + QRE_Value6) / 6; // Soma todos os valores e divide pela quantidade de números no conjunto


if (QRE_Value1 < 750 && QRE_Value8 > 750)
  {
        Serial.println("Vire a direita");
  }

else if (QRE_Value8 < 750 && QRE_Value1 > 750)
  {
        Serial.println("Vire a esquerda");
  }

else if (QRE_Value1 > 750 && QRE_Value8 > 750)
  {
        Serial.println("Siga em frente");
  }

  Serial.println("_______________________");
  
  delay(2000);
}
