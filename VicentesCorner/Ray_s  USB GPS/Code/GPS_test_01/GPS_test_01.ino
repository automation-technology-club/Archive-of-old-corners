/*GPS_test.ino     Agrucho 15 FEB 2017
 Testing the Ray's USB GPS.
-USB cable removed.
-An internal cable was connected to the TX TTL signal
     GPS Model: BU-303
     S/N: BU058912
     MADE IN TAIWAN
-Send NMEA format @ 4800 Bauds ever second.
*/

#include <SoftwareSerial.h>

#define  TXDATA   2
#define  RXDATA   3
#define  RXLED   13

SoftwareSerial mySerial(RXDATA, TXDATA);

void setup() {
 Serial.begin(9600); //This baud rate will help a lot in printing all of the data that comes from the GPS Module to the serial monitor
 mySerial.begin(4800);
}

void loop() {
  if (mySerial.available()) {
    tone(RXLED, 2000, 20);            // Signaling incoming DATA from the GPS.
    Serial.write(mySerial.read());
  }
}
