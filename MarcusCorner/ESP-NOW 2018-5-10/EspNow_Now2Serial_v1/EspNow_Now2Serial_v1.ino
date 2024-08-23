/*   
   Description:  ESP-NOW to SERIAL GATEWAY node: 
                 ESP-Now protocol  
                 ESP8266 MCU ESP-12
   
  System Architecture: [Sensor-ESP-NOW]-[ESP-NOW to SERIAL GATEWAY]-[SERIAL to WIFI]   
                   
  Developer:     Marcus Davis
  
  Release Notes: 4/28/2018 : Created

  Contributors:
  Anthony Elder,  2018  https://github.com/HarringayMakerSpace/ESP-Now
  Andreas Spiess, 2017  https://github.com/HarringayMakerSpace/ESP-Now
                  
*/
 
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
SoftwareSerial nowSerial(13, 15, false, 256);  // RX(D7), TX(D8)

extern "C" {
  #include "user_interface.h"
  #include <espnow.h>
}
// Set Mac address  
uint8_t mac[] = {0x36, 0x33, 0x33, 0x33, 0x33, 0x33};
void initVariant() {
  WiFi.mode(WIFI_AP);
  wifi_set_macaddr(SOFTAP_IF, &mac[0]);
}

// keep in sync with ESP_NOW sensor struct
struct __attribute__((packed)) SENSOR_DATA {
     float temp;
     float humidity;    
     float vcc;
     unsigned long deviceid;
} sensorData;

int heartBeat;

void setup() {
    nowSerial.begin(9600);
    nowSerial.println("Now Serial Open");
    Serial.begin(115200); 
    Serial.println();
    Serial.println();
    Serial.println("ESP_Now Now to Serial Gateway");
    Serial.println();
  
    Serial.print("This node AP mac: "); Serial.print(WiFi.softAPmacAddress()); Serial.println(" (Assign to remoteMac[] variable in the Sensor Node sketch)");
    Serial.print("This node STA mac: "); Serial.println(WiFi.macAddress());
    Serial.println();
    initEspNow();  
    Serial.println("Setup done");
}

void loop() {
  
  if (millis()-heartBeat > 30000) {
    Serial.println("Waiting for ESP-NOW messages...");
    heartBeat = millis();
  }
  
}

void sendPayload() {

  String payload = "{\"mailbox\":{";
  payload += "\"temp\":" + String(sensorData.temp, 1) + ",";
  payload += "\"humidity\":" + String(sensorData.humidity, 0) + ",";
  payload += "\"supply\":" + String(sensorData.vcc, 0) + ",";
  payload += "\"deviceid\":" + String(sensorData.deviceid) ;
  payload += "}}";
  nowSerial.println(payload);

}

void initEspNow() {
  if (esp_now_init()!=0) {
    Serial.println("*** ESP_Now init failed");
    ESP.restart();
  }
  
    esp_now_set_self_role(ESP_NOW_ROLE_COMBO );
  
    esp_now_register_recv_cb([](uint8_t *mac, uint8_t *data, uint8_t len) {
  
        memcpy(&sensorData, data, sizeof(sensorData));

        Serial.println("Serial Data Sent");
        sendPayload();
  
  });
}


