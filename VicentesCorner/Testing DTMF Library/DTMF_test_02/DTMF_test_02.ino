/*DTMF_test_02.ino    Agrucho 08 FEB 2016
Sketch found at: http://forum.arduino.cc/index.php?topic=121540.0
My comments:
Using Sparkfun Microphone.
Analog reference = VCC.
The DC level is VCC/2 = 512

*/

// The library toggles digital pin 4 in the sampling loop which allows
// measurement of the actual sampling frequency.
// If you call .sample() continuously like this:
// while(1)dtmf.sample(AUDIOIN);
// you can put a frequency counter on pin 4 to determine what the
// sampling frequency is on your Arduino. Note that the frequency
// counter will show half the actual rate. My meter showed 4.463kHz
// so the sampling rate is 8926Hz

//#include <DTMF.h>
#include "DTMF.h"

#define  AUDIOIN   A0
#define  S_RATE    8926.0  // sampling rate in Hz
#define  BUFFSIZE  128     // number of samples taken.
#define  led       13


// NOTE that BUFFSIZE MUST NOT exceed 160
// This is the number of samples which are taken in a call to
// .sample. The smaller the value of N the wider the bandwidth.
// For example, with N=128 at a sample rate of 8926Hz the tone
// detection bandwidth will be 8926/128 = 70Hz. If you make BUFFSIZE
// smaller, the bandwidth increases which makes it harder to detect
// the tones because some of the energy of one tone can cross into
// an adjacent (in frequency) tone. But a larger value of BUFFSIZE also means
// that it takes longer to collect the samples.
// A value of 64 works just fine, as does 128.
// NOTE that the value of BUFFSIZE does NOT have to be a power of 2.

int nochar_count = 0;
float d_mags[8];

// Instantiate the dtmf library with the buffer size and the sampling rate.
DTMF dtmf = DTMF(BUFFSIZE,S_RATE);

//=============================================================================
void setup(){
  pinMode(led, OUTPUT);
//  analogReference(INTERNAL);  // built-in reference (1.1 volts)    
  Serial.begin(115200);
}

//=============================================================================
void loop(){
  char thischar;

  // This reads N samples from AUDIOIN (must be an analog input)
  // and stores them in an array within the library. Use while(1)
  // to determine the actual sampling frequency as described in the
  // comment at the top of this file
  /* while(1) */
  
 //----------Measuring signal dc level and amplitud --------------------- 
 /*
  int newval, dclevel;
  int bigest=0;
  
  dclevel= analogRead(AUDIOIN);
  Serial.print(dclevel);
  Serial.print(">");
  for(int i=0; i<100;i++){
    newval = abs(analogRead(AUDIOIN)-dclevel);
    if (newval > bigest) bigest=newval ;  
  }
  Serial.println(bigest);
  delay(100);
*/
  //amplitudes de 1 hasta 200
  //Con bajo nivel de señal dclevel estable a 684
  //Se observan declevel fluctuando de 523 a 750 (esto es muy ruidoso)
  // Aumentando condensador de 1uF a 10uF (634 a 733)(todavia ruidoso)
//-------------------------------------------------
  
  dtmf.sample(AUDIOIN);   //Reads BUFFSIZE samples from AUDIOIN
  
  // The first argument is the address of a user-supplied array
  // of 8 floats in which the function will return the magnitudes
  // of the eight tones.
  // The second argument is the value read by the ADC when there
  // is no signal present. A voltage divider with precisely equal
  // resistors will presumably give a value of 511 or 512.
  // My divider gives a value of 506.
  // If you aren't sure what to use, set this to 512
  
  dtmf.detect(d_mags,512);                      //DC level (Vcc/2)

  // detect the button
  // If it is recognized, returns one of 0123456789ABCD*#
  // If unrecognized, returns binary zero

  // Pass it the magnitude array used when calling .sample
  // and specify a magnitude which is used as the threshold
  // for determining whether a tone is present or not
  //
  // If N=64 magnitude needs to be around 1200
  // If N=128 the magnitude can be set to 1800
  // but you will need to play with it to get the right value
  
  thischar = dtmf.button(d_mags,1800.);
  if(thischar) {
    Serial.print(thischar);
    nochar_count = 0;
    // Print the magnitudes for debugging
//#define DEBUG_PRINT
#ifdef DEBUG_PRINT
    for(int i = 0;i < 8;i++) {
      Serial.print("  ");
      Serial.print(d_mags[i]);
    }
    Serial.println("");
#endif
  } else {
    // print a newline 
    if(++nochar_count == 50)Serial.println("");
    // don't let it wrap around
    if(nochar_count > 30000)nochar_count = 51;
  }
}
