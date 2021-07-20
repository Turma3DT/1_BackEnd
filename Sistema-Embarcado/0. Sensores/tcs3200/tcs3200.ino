//Programa: Sensor TCS3200 e led RGB
//Autor: FILIPEFLOP
 
//Pinos de conexao do modulo
const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;
 
//Variaveis cores
int red = 0;
int green = 0;
int blue = 0;
 
void setup()
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  Serial.begin(9600);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
}
 
void loop()
{
  //Detecta a cor
  color();
  //Mostra valores no serial monitor
  Serial.print("Vermelho :");
  Serial.print(red, DEC);
  Serial.print(" Verde : ");
  Serial.print(green, DEC);
  Serial.print(" Azul : ");
  Serial.print(blue, DEC);
  Serial.println();
 
 // condiçoes para detecção das cores e atuação do servo motor
  if (47 < red && red < 70 &&  140 < green && green < 180 && 110 < blue && blue < 130){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Vermelho"); 
    }
  else if (140 < red && red < 160 && 85 < green < green < 115 && 45< blue && blue < 65){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Azul");
    }
  else if (150 < red && red < 175 &&  130< green && green < 155 && 120< blue && blue < 140){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Verde");
    }
  else if (30<red&&red<55 &&  110 < green && green < 135 && 105 < blue && blue < 125){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Laranja");
    }
  else if (25 < red && red < 70 &&  35 < green && green < 100 && 55 < blue && blue < 170){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Amarelo");
    }
  else if (65 < red && red < 90 &&  100 < green && green < 120 && 50 < blue && blue < 77){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Roxo");
    }
  else if (115 < red && red < 135 &&  155 < green && green < 170 && 110 < blue && blue < 140){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Marron");
    }
  else if (80 < red && red < 95 &&  55 < green && green < 70 && 35 < blue && blue < 50){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Azul Claro");
    }
  else if (74 < red && red < 90 &&  45 < green && green < 75 && 60 < blue && blue < 90){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo Serial.println("| Verde Claro"); servo.write(130);} else if (red > 240 && green > 270 && blue > 200){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Preto");}
  else if (red < 70 && green < 70 && blue < 70){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Branco");}
    Serial.println(); // quebra um linha no texto do serial monitor
    delay(300); // atraso de 300 milisegundos

}
 
void color()
{
  //Rotina que le o valor das cores
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //count OUT, pRed, RED
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  //count OUT, pBLUE, BLUE
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  //count OUT, pGreen, GREEN
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
