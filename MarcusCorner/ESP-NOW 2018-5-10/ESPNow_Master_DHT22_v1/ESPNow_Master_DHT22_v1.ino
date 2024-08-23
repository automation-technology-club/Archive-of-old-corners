/*   
   Description:  Temperature and humidity sensor node: 
                 ESP-Now protocol  
                 DHT-22, ESP8266 MCU ESP-12
   
  System Architecture: [Sensor-ESP-NOW]-[ESP-NOW to SERIAL GATEWAY]-[SERIAL to WIFI]   
                   
  Developer:     Marcus Davis
  
  Release Notes: 4/28/2018 : Created

  Contributors:
  Anthony Elder,  2018  https://github.com/HarringayMakerSpace/ESP-Now
  Andreas Spiess, 2017  https://github.com/HarringayMakerSpace/ESP-Now
                  
*/
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <DHT_U.h>

extern "C" { 
  #include <espnow.h>  
  }
  
#define DHTPIN    2        // Connect to D4 on ESP8266 MCU
#define DHTTYPE   DHT22    // DHT 22 (AM2302)

#define WIFI_CHANNEL 1
#define SLEEP_SECS 5      // 15 minutes
#define SEND_TIMEOUT 245  // 245 millis seconds timeout 

DHT dht(DHTPIN, DHTTYPE);

// The following is the MAC Address of the remote ESP-NOW to SERIAL GATEWAY
// This module (Sensor ESP-NOW) send data to ESP-NOW to SERIAL GATEWAY
uint8_t remoteMac[] = {0x36, 0x33, 0x33, 0x33, 0x33, 0x33};

unsigned long entry;

// keep in sync with slave struct
struct __attribute__((packed)) SENSOR_DATA {
     float temp;
     float humidity;    
     float vcc;
     unsigned long deviceid;
} sensorData;

// volatile will attempt to optimize callback
volatile boolean callbackCalled;
// Start timer
unsigned long entry1 = millis();
// Enable internal voltage variable
ADC_MODE(ADC_VCC);

void setup() {
      dht.begin();

      Serial.begin(115200);
      Serial.println("ESP_Now Sensor Node");
         
      WiFi.mode(WIFI_STA); // Station mode for esp-now sensor node
      WiFi.disconnect();
    
      Serial.printf("This mac: %s, ", WiFi.macAddress().c_str());
      Serial.printf("target mac: %02x%02x%02x%02x%02x%02x", remoteMac[0], remoteMac[1], remoteMac[2], remoteMac[3], remoteMac[4], remoteMac[5]);
      Serial.printf(", channel: %i\n", WIFI_CHANNEL);
      Serial.println("");
    
      readDHT22();
    
      if (esp_now_init() != 0) {
        Serial.println("*** ESP_Now init failed");
        gotoSleep();
      }
      esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
      
      esp_now_add_peer(remoteMac, ESP_NOW_ROLE_SLAVE, WIFI_CHANNEL, NULL, 0);
    
      esp_now_register_send_cb([](uint8_t* mac, uint8_t sendStatus) {
        Serial.printf("send_cb, send done, status = %i\n", sendStatus);
        callbackCalled = true;
      });
    
      callbackCalled = false;
}

void loop() {

  uint8_t bs[sizeof(sensorData)];
  memcpy(bs, &sensorData, sizeof(sensorData));

  unsigned long entry = millis();
  esp_now_send(NULL, bs, sizeof(sensorData)); // NULL means send to all peers
  Serial.print("Time to send: ");
  Serial.println(millis() - entry1);
  ESP.deepSleep(0);
}

void readDHT22()
  {
    delay(400);
     // Get temperature event and print its value.
    sensors_event_t event;  
     
    if (isnan(dht.readTemperature())) {
      Serial.println("Error reading temperature!");
    }
    else {
      Serial.print("Temperature: ");
      Serial.print(dht.readTemperature(true));
      Serial.println(" *F");
      sensorData.temp = dht.readTemperature(true);
    }
    // Get humidity event and print its value.
  
    if (isnan(dht.readHumidity())) {
      Serial.println("Error reading humidity!");
    }
    else {
      Serial.print("Humidity: ");
      Serial.print(dht.readHumidity());
      Serial.println("%");
      sensorData.humidity = dht.readHumidity();
    }
    sensorData.vcc = ESP.getVcc();
    sensorData.deviceid = 18040502;
    Serial.print("Supply: ");
    Serial.print(sensorData.vcc);
    Serial.println(" mVDC");
    Serial.print("Device ID: ");
    Serial.println(sensorData.deviceid);
}


void gotoSleep() {
  // add some randomness to avoid collisions with multiple devices
  int sleepSecs = SLEEP_SECS;// + ((uint8_t)RANDOM_REG32/2);
  Serial.printf("Up for %i ms, going to sleep for %i secs...\n", millis(), sleepSecs);
  ESP.deepSleep(sleepSecs * 1000000, RF_NO_CAL);
}
