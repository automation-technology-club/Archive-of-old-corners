/*************************************************** 
 Some corrections and additions by Agrucho 04 JAN 2017.
 The SparkFun library has a lot of other functions.
 
----------------------------------------------------
  This is a library for the MLX90614 Temp Sensor

  Designed specifically to work with the MLX90614 sensors in the
  adafruit shop
  ----> https://www.adafruit.com/products/1748
  ----> https://www.adafruit.com/products/1749

  These sensors use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruied in any redistribution
 ****************************************************/


#include "Arduino.h"
#include <Wire.h>

#define MLX90614_I2CADDR 0x5A    // I2C Address.

// RAM registers:
#define MLX90614_RAWIR1  0x04
#define MLX90614_RAWIR2  0x05
#define MLX90614_TA      0x06
#define MLX90614_TOBJ1   0x07
#define MLX90614_TOBJ2   0x08
// EEPROM registers:
#define MLX90614_TOMAX   0x20
#define MLX90614_TOMIN   0x21
#define MLX90614_PWMCTRL 0x22    // PWM control (configures PWM/SDA pin).
#define MLX90614_TARANGE 0x23
#define MLX90614_EMISS   0x24    // Emissivity correction coefficient.
#define MLX90614_CONFIG  0x25    // Config Register1 (Check: melexis-mlx90614-on-chip-digital.pdf)
                                 // Bits[13:11]: Gain control.
                                 // Bits[10:8]: FIR Filter settings.
                                 // Bits[2:0]: IIR Filter settings.
#define MLX90614_ADDR    0x2E    // SMBus Address (LSByte only)
// Other registers:
#define MLX90614_ID0     0x3C    // ID number
#define MLX90614_ID1     0x3D    // ID number 
#define MLX90614_ID2     0x3E    // ID number
#define MLX90614_ID3     0x3F    // ID number
#define MLX90614_SLEEP   0xFF    // Enter sleep mode.

class Adafruit_MLX90614  {
 public:
  Adafruit_MLX90614(uint8_t addr = MLX90614_I2CADDR);
  boolean begin();
  uint32_t readID(void);

  double readObjectTempC(void);
  double readAmbientTempC(void);
  double readObjectTempF(void);
  double readAmbientTempF(void);

 private:
  float readTemp(uint8_t reg);

  uint8_t _addr;
  uint16_t read16(uint8_t addr);
  void write16(uint8_t addr, uint16_t data);
};

