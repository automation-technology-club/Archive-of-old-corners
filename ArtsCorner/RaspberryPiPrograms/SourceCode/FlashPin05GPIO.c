/* This program sets GPIO pin #4 to OUTPUT then toggles the pin from LOW to HIGH for a fixed period and repeats ad infinitum. */ 
/* Written 6/20/2016 */

#include <stdio.h>
#include <wiringPi.h>

#define Period 200

int i;
int flashPin =5;


int main()
{
	// The wiringPiSetup() function initialiazes the library.  Without this command, the program does nothing.
	wiringPiSetup();
//	wiringPiSetupGpio();
	printf("Set all gpio pins to OUTPUT\n");

	pinMode(flashPin, OUTPUT);
	
	while(1){
	printf("Toggle GPIO pin 4 HIGH for %d mSec then LOW for %d mSec\n", Period, Period);
		digitalWrite(flashPin, HIGH);
		printf("Set pin %d HIGH\n", i);
		delay(Period);
		digitalWrite(flashPin, LOW);
		printf("Set pin %d LOW\n", i);
		delay(Period);
	}

	return 0;
}

