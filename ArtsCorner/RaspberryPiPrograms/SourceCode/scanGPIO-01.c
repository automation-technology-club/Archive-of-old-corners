
/* This program scans the GPIO pins and sets them all to LOW." Written 6/20/2016 */
/* This program sets the first 7 GPIO pins to OUTPUT mode then toggles them HIGH and LOW for Period mSecs in sequence. */

#include <stdio.h>
#include <wiringPi.h>

#define Period 250

int i;
int indexLED = 0;

int main()
{
	// The wiringPiSetup() function initiallizes the library.  Without this command, the program does nothing.
	wiringPiSetup();
//	wiringPiSetupGpio();
	printf("Set all gpio pins to OUTPUT\n");

	for(i = 0; i < 40 ; i++){
		pinMode(i , OUTPUT);
		printf("Set pin %d to OUTPUT\n", i);
	}

	
	while(1){

/*
		printf("Toggle each gpio pin HIGH for %d mSec then LOW for %d mSec\n", Period, Period);
		for(i = 0; i < 40 ; i++){
			printf("Pin # %d\n", i);
			digitalWrite(i, HIGH);
			printf("Set pin %d HIGH\n", i);
			delay(Period);
			digitalWrite(i, LOW);
			printf("Set pin %d LOW\n", i);
			delay(Period);
		}
*/

// This code scans the first 8 pins; 0,1,2,3,4,5,6,21; and toggles the pin high for Period then LOW for Period.
// Note that the 8th pin is not in sequence due to the crazy GPIO pin numbering.

	for(indexLED = 0; indexLED < 40 ; indexLED++){
		switch(indexLED){
			case 0: {
				digitalWrite(indexLED, HIGH);
				delay(Period);
				digitalWrite(indexLED, LOW);
				delay(Period);
				}
				break;
			case 1: {
				digitalWrite(indexLED, HIGH);
				delay(Period);
				digitalWrite(indexLED, LOW);
				delay(Period);
				}
				break;
			case 2: {
				digitalWrite(indexLED, HIGH);
				delay(Period);
				digitalWrite(indexLED, LOW);
				delay(Period);
				}
				break;
			case 3: {
				digitalWrite(indexLED, HIGH);
				delay(Period);
				digitalWrite(indexLED, LOW);
				delay(Period);
				}
				break;
			case 4: {
				digitalWrite(indexLED, HIGH);
				delay(Period);
				digitalWrite(indexLED, LOW);
				delay(Period);
				}
				break;
			case 5: {
				digitalWrite(indexLED, HIGH);
				delay(Period);
				digitalWrite(indexLED, LOW);
				delay(Period);
				}
				break;
			case 6: {
				digitalWrite(indexLED, HIGH);
				delay(Period);
				digitalWrite(indexLED, LOW);
				delay(Period);
				}
				break;
			case 7: {
				digitalWrite(indexLED, HIGH);
				delay(Period);
				digitalWrite(indexLED, LOW);
				delay(Period);
				}
				break;
			case 21: {
				digitalWrite(indexLED, HIGH);
				delay(Period);
				digitalWrite(indexLED, LOW);
				delay(Period);
				}
				break;
			default: break;
			}
		}

	}
	return 0;
}

