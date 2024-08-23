/*Due_60Hz_Int_Two_Pot_02.ino     Agrucho  24 MAY 2016

 Using the DueTimer library to implement 3 interrupt tasks:
 1.- dummy(), prints  "dummy ..." every second.
 2.- genWave(), generates the two 60Hz signals.
 3.- ledBlinking(), blinks a LED every second.
 
60 Hz waves generation using interrupts (DAC0 and DAC1 of the Arduino DUE).
120 samples/period are used.
Test to make a 60Hz three phase power supply.
  The signals will be used with an Audio amplifier to drive two transformers (12/270VAC)24VA.
  The transformers output are connected to generate two sides of a three-phase
  AC source in delta configuration.

Wave 0 in DAC0, 60 Hz, phase= 0 degrees.
Wave 1 in DAC1, 60 Hz, phase= 60 degrees.
Amplitud of Wave 0 is controlled with a Pot in A0.
Amplitud of Wave 1 is controlled with a Pot in A1.

ToDo:
-Change phase sequence (reversing) using a push button.
-Produce phase displacement using another potentiometer.

*/

#include <DueTimer.h>

#define led_pin     13
#define RESOLUTION  8      // Resolution bits of the D/A converter.
#define POINTS      120    // Wave points.(256 max. to keep offset as char type)
#define PEAKVAL     int(pow(2,RESOLUTION)/2)    // Wave Amplitud (128 max, inside 8-Bits range)
#define OFFSET      int(pow(2,RESOLUTION)/2)    // Center of the wave (128 for full 8-Bits span)
#define PERIOD      (1000000/60/POINTS)+1    // +1 to calibrate.

int sintable0[POINTS];    // Array to load the sin table data.
int sintable1[POINTS];    // Array to load the sin table data.
int indext=0;
int state = false;

void genWave(){
  analogWrite(DAC0, sintable0[indext]);
  analogWrite(DAC1, sintable1[indext]);
  indext++;
  if(indext >= POINTS)indext=0; // Keep indext in range.
}

void ledBlinking(){
  state = !state;
  digitalWrite(led_pin, state);
  Serial.print(analogRead(A0));
  Serial.print(",");
  Serial.println(analogRead(A1));
}
void dummy(){
  Serial.println("dummy ...");
}

//======================= setup =========================================
void setup(){
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, LOW);
	Serial.begin(9600);
  analogWriteResolution(RESOLUTION);
  //Creating 3 interrupt tasks:
  Timer.getAvailable().attachInterrupt(dummy).start();              // dummy interrupt every second (default).
  delay(50);
	Timer.getAvailable().attachInterrupt(genWave).start(PERIOD);      // 120 samples/period.
  delay(50);
	Timer.getAvailable().attachInterrupt(ledBlinking).start(500000);  // Every 500 milliseconds.
  delay(50);
  fillTable0(PEAKVAL);
  fillTable1(PEAKVAL);
}

//========================= loop ========================================
void loop(){
  fillTable0(analogRead(A0)/8);
  fillTable1(analogRead(A1)/8);
  delay(50);
}

/*----------------------------------------------------------------------------
 Subroutine to fill the sintable0 with POINTS samples and amplitude:
  --------------------------------------------------------------------------*/
 void fillTable0(int amplitude){
  for ( int i = 0; i < POINTS; i++ ) {
    sintable0[i] = sin( i * 3.141592 * 2 / POINTS ) * (amplitude-1) + OFFSET ;
  }
}
 
/*----------------------------------------------------------------------------
 Subroutine to fill the sintable1 with POINTS samples and amplitude,
 Phase displacement= 60 degrees (Pi/3= 1.0472)
  --------------------------------------------------------------------------*/
 void fillTable1(int amplitude){
  for ( int i = 0; i < POINTS; i++ ) {
    sintable1[i] = sin( 1.0472 + (i * 3.141592 * 2 / POINTS) ) * (amplitude-1) + OFFSET ;
  }
//  sintable1[0]=128;   //<< MARK some times the nano scope dont see it!
}

