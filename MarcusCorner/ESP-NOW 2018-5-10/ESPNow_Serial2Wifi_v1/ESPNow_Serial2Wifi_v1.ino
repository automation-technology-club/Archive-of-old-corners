/*
   Description:  SERIAL to WIFI > MQTT node: 
                 SoftwareSerial  
                 DHT-22, ESP8266 MCU ESP-12
   
  System Architecture: [Sensor-ESP-NOW]-[ESP-NOW to SERIAL GATEWAY]-[SERIAL to WIFI]   
                   
  Developer:     Marcus Davis
  
  Release Notes: 4/28/2018 : Created

  Contributors:
  Anthony Elder,  2018  https://github.com/HarringayMakerSpace/ESP-Now
  Andreas Spiess, 2017  https://github.com/HarringayMakerSpace/ESP-Now
*/
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <PubSubClient.h>
#include "credentials.h"
#define BAUD_RATE 9600
#define MQTT_MAX_PACKET_SIZE 512

SoftwareSerial swSer(13, 15, false, 256); // RX(07), TX(08)

//-------- Customize these values -----------
const char* ssid = _ssid;
const char* password = _password;
const char* mqtt_server = _mqtt_server;
const char* SENDTOPIC = _SENDTOPIC;
//-------- Customise the above values --------

WiFiClient wifiClient;
PubSubClient client(mqtt_server, 1883, wifiClient);

String data = "";

void setup() {
  
  Serial.begin(115200); Serial.println();
  swSer.begin(BAUD_RATE);

  wifiConnect();
  reconnectMQTT();
}

void loop() {
      char character;     
      while(swSer.available())
      {
        character = swSer.read();
        data += character;

        if (character == 10) {  
          Serial.print("Received: ");
          Serial.print(data);
          readSerial(data);
          data = "";
        } 
      }
}

void readSerial(String data1) {
    // Send MQTT data 
    publishMQTT(SENDTOPIC,data1);
}

void wifiConnect() {
  WiFi.mode(WIFI_STA);
  Serial.print("Connecting to "); Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
     delay(250);
     Serial.print(".");
  }  
  Serial.print("\nWiFi connected, IP address: "); Serial.println(WiFi.localIP());
}

void publishMQTT(String topic, String message) {
  Serial.print("Published: "); Serial.print("Topic: "); Serial.print(topic); 
  Serial.print("  Payload: "); Serial.println(message);
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.publish(SENDTOPIC, message.c_str());
}

void reconnectMQTT() {
  
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect

    if (client.connect("MQTT")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc = ");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
