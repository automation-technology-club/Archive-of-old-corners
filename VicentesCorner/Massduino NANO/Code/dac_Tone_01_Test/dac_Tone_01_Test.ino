/*dac_Tone_01_Test.ino   Agrucho 6 FEB 2017
Testing the Digital-to-Analog capability of the Massduino NANO.

Generating a 4.155 Khz tone of 8 cycles every 500 milliseconds.
using the DAC0 (Pin 4) of the Massduino NANO (MD-328D).
The Masduino NANO has two DACs:
   DAC0 output ==> D4 on Arduino (Tested with the oscilloscope)
   DAC1 output ==> PE5 (Pin 6 MD-328D TQFP-32) Pin not available in the Massduino NANO.
      (Tested with the oscilloscope at the pin 6 of the MD-328D)
   
*/

#define POINTS    32        // Number of samples in one cycle.
#define WAVESIZE  256       // Wave points.(256 max. to keep offset as char type)
#define PEAKVAL   128       // Wave Amplitud (128 max, to avoid exceed the 8-Bits range)
#define OFFSET    128       // Center of the wave (128 for full 8-Bits span).

int sintable[WAVESIZE];     //Array to load the wave.
unsigned char offset=0;     // index to point to the data inside sintable[].

void setup() {
  pinMode(13, OUTPUT);
//  analogReference(INTERNAL2V56);
  pinMode(4, ANALOG);

// Fill the sin table with SAMPLES samples:
  for ( int i = 0; i <= WAVESIZE; i++ ) {
    sintable[i] = sin( i * 3.141592 * 2 / POINTS ) * (PEAKVAL-1) + OFFSET ;
  }
}

void loop() {  
  analogWrite(4, sintable[offset]);
  if(offset==0){
    digitalWrite(13, LOW);    // turn the LED off
    delay(500);               // Delay between tones.
    digitalWrite(13, HIGH);   // turn the LED on    
  }
  offset++;
}

