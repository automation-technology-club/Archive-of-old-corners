/*Massduino_two_DACs.ino Agrucho 13 FEB 2017
Generating two sine waves with the Massduino NANO
Wave0 --> DAC0 (Pin 4) of the Massduino NANO (MD-328D).
Wave1 --> DAC1 (Pin 3) (Pin 6 MD-328D TQFP-32 connected to D3 using 1K reistor).
The Masduino NANO has two DACs:
   DAC0 output ==> (4)  D4 on Arduino (Tested with the oscilloscope)
   DAC1 output ==> (22) PE5 (Pin 6 MD-328D TQFP-32) Pin not available in the Massduino NANO.
      (1k resistor connected between pin 6 of MD-328D to pin D3)  
*/

#define POINTS    256       // Number of samples in one cycle.
#define WAVESIZE  256       // Wave points.(256 max. to keep offset as char type)
#define PEAKVAL   128       // Wave Amplitud (128 max, to avoid exceed the 8-Bits range)
#define OFFSET    128       // Center of the wave (128 for full 8-Bits span).

int sintable[WAVESIZE];     //Array to load the wave.
unsigned char offset0=0;     // index to point to the data inside sintable[].
unsigned char offset1=64;    // index to point to the data inside sintable[].
void setup() {
  pinMode(13, OUTPUT);
//  analogReference(INTERNAL2V56);
  pinMode(4, ANALOG);
  pinMode(22, ANALOG);
// Fill the sin table with SAMPLES samples:
  for ( int i = 0; i <= WAVESIZE; i++ ) {
    sintable[i] = sin( i * 3.141592 * 2 / POINTS ) * (PEAKVAL-1) + OFFSET ;
  }
}

void loop() {  
  analogWrite(4, sintable[offset0]);
  analogWrite(22, sintable[offset1]);
/*  
  if(offset==0){
    digitalWrite(13, LOW);    // turn the LED off
    delay(500);               // Delay between tones.
    digitalWrite(13, HIGH);   // turn the LED on    
  }
 */
  offset0++;
  offset1= offset0+ analogRead(A0)/8;  //Phase displacement control.
  //delayMicroseconds(6);      // To adjust frequency (13.11 Hz when commented)
}

