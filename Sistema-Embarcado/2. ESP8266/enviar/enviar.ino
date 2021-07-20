#include <ArduinoJson.h>


void setup()
{
  Serial.begin(9600); 
}

void loop() 
{ 
  DynamicJsonDocument doc(1024);
  
    doc["stats"] = 1;
    doc["motor1"] = 1;
    doc["motor2"] = 1;
    doc["bateria"] = 1;

    Serial.write("?");
    serializeJson(doc, Serial);
    Serial.write("!");    

  delay(10000);
}
