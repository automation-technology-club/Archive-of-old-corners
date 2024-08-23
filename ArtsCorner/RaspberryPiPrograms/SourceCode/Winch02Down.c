/* Winch01Down.c */
/* Winch01 is controlled by GPIO pins 0 & 1. 7/12/16 */
/* This program sets GPIO pin 0 LOW, GPIO pin 1 HIGH and returns control to the calling script. 7/12/16 */

#include <stdio.h>
#include <wiringPi.h>

int winchPin0 = 2;
int winchPin1 = 3;

int main()
{
	// The wiringPiSetup() function initialiazes the library.  Without this command, the program does nothing.
	wiringPiSetup();
//	wiringPiSetupGpio();
	printf("Set selected gpio pin to OUTPUT.\n");
	pinMode(winchPin0, OUTPUT);
	pinMode(winchPin1, OUTPUT);
	printf("Set pin 0 LOW and pin 1 HIGH.\n");
	digitalWrite(winchPin0, LOW);
	digitalWrite(winchPin1, HIGH);
	printf("GPIO pin 0 is now set LOW and GPIO pin 1 is set HIGH.\n");	
	return 0;
}

