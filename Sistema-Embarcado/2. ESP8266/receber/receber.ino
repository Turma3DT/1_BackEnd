//Include da lib de Wifi do ESP8266
#include <ESP8266WiFi.h>
//Include da lib de ArduinoJson
#include <ArduinoJson.h>
 
//Definir o SSID da rede WiFi
const char* ssid = "AAPM";
//Definir a senha da rede WiFi
const char* password = "";
 
//Colocar a API Key para escrita neste campo
//Ela é fornecida no canal que foi criado na aba API Keys
String apiKey = "4HXW4Y4JMDTCN77X";       //trocar pela API Write
const char* server = "api.thingspeak.com";

WiFiClient client;
 
void setup() {
  //Configuração da UART
  Serial.begin(9600);
  //Inicia o WiFi
  WiFi.begin(ssid, password);
 
  //Espera a conexão no router
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  //Logs na porta serial
  Serial.println("");
  Serial.print("Conectado na rede ");
  Serial.println(ssid);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

String antigo = "";
String atual = "";
String postStr = apiKey;

float stats = 0;
float motor1 = 0;
float motor2 = 0;
float bateria = 0;

 
void loop() {
  if (Serial.available() > 0) {
    DynamicJsonDocument doc(1024);
    char carac = Serial.read();
    //Serial.println(carac);

    if (carac == '?') {
      //antigo = atual;
      atual = "";
     } 
     else if (carac == '!') {
      postStr = apiKey;
      Serial.print("Json: ");
      Serial.println(atual);

      String json = String(atual);
      deserializeJson(doc, json);

      Serial.print("Json String: ");
      Serial.println(json); 

      stats = doc["stats"];
      motor1 = doc["motor1"];

      Serial.print("Status: ");
      Serial.println(stats); 

      Serial.print("Motor 1: ");
      Serial.println(motor1); 

      
      postStr +="&field1=";
      postStr += stats;
      postStr +="&field2=";
      postStr += motor1;

      postStr += "\r\n\r\n";
      
      if (client.connect(server, 80)) {
        client.print("POST /update HTTP/1.1\n");
        client.print("Host: api.thingspeak.com\n");
        client.print("Connection: close\n");
        client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
        client.print("Content-Type: application/x-www-form-urlencoded\n");
        client.print("Content-Length: ");
        client.print(postStr.length());
        client.print("\n\n");
        client.print(postStr);
    
        Serial.print("Status: ");
        Serial.println(stats);
        Serial.print("Motor 1: ");
        Serial.println(motor1);  
        
      }
      
     } 
     else {
      atual += String(carac);
     }
 
  }
  
  
  client.stop();
}
