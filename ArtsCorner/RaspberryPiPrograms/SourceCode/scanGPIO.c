

/* This program scans the GPIO pins and sets them all to LOW." Written 6/20/2016 */
/* This program sets the first 7 GPIO pins to OUTPUT mode then toggles them HIGH and LOW for Period mSecs in sequence. */

#include <stdio.h>
#include <wiringPi.h>

#define Period 50


int i;


int main()
{
	// The wiringPiSetup() function initialiazes the library.  Without this command, the program does nothing.
	wiringPiSetup();
//	wiringPiSetupGpio();
	printf("Set all gpio pins to OUTPUT\n");

	for(i = 0; i < 0x07 ; i++){
//	for(i = 0x07; i < 40 ; i++){
		pinMode(i , OUTPUT);
		printf("Set pin %d to OUTPUT\n", i);
	}

	
	while(1){
		printf("Toggle each gpio pin LOW for %d mSec then HIGH for %d mSec\n", Period, Period);
		for(i = 0; i < 0x07 ; i++){
//		for(i = 0x07; i < 40 ; i++){
			printf("Pin # %d\n", i);
			digitalWrite(i, HIGH);
			printf("Set pin %d HIGH\n", i);
			delay(Period);
			digitalWrite(i, LOW);
			printf("Set pin %d LOW\n", i);
			delay(Period);
		}
	}
	return 0;
}

