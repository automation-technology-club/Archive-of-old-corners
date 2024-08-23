/* Winch01Up.c */
/* Winch01 is controlled by GPIO pins 0 & 1. 7/12/16 */
/* This program sets GPIO pin 0 HIGH, GPIO pin 1 LOW and returns control to the calling script. 7/12/16 */

#include <stdio.h>
#include <wiringPi.h>

int winchPin0 = 6;
int winchPin1 = 7;

int main()
{
	// The wiringPiSetup() function initialiazes the library.  Without this command, the program does nothing.
	wiringPiSetup();
//	wiringPiSetupGpio();
	printf("Set selected gpio pin to OUTPUT.\n");
	pinMode(winchPin0, OUTPUT);
	pinMode(winchPin1, OUTPUT);
	printf("Set pin 0 HIGH and pin 1 LOW.\n");
	digitalWrite(winchPin0, HIGH);
	digitalWrite(winchPin1, LOW);
	printf("GPIO pin 0 is now set HIGH and GPIO pin 1 is set LOW.\n");	
	return 0;
}

