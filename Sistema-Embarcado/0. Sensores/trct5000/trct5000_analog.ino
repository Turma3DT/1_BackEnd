#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4

void setup() {

  Serial.begin(9600);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
}



void loop() {
  //Reading Sensor Values
  int s1 = analogRead(ir1);  //Left Most Sensor
  int s2 = analogRead(ir2);  //Left Sensor
  int s3 = analogRead(ir3);  //Middle Sensor
  int s4 = analogRead(ir4);  //Right Sensor
  int s5 = analogRead(ir5);  //Right Most Sensor

  Serial.print("S1 = ");
  Serial.println(s1);
  Serial.println("-------------------");
  Serial.print("s2 = ");
  Serial.println(s2);
  Serial.println("-------------------");
  Serial.print("s3 = ");
  Serial.println(s3);
  Serial.println("-------------------");
  Serial.print("s4 = ");
  Serial.println(s4);
  Serial.println("-------------------");
  Serial.print("s5 = ");
  Serial.println(s5);
  Serial.println("-------------------");
  Serial.println("");
  delay(500);
}
