/* MusicOn.c */
/* MusicOn is controlled by GPIO pins 0 & 1. 7/12/16 */
/* This program sets GPIO pin 12 HIGH, GPIO pin 1 LOW and returns control to the calling script. 7/12/16 */

#include <stdio.h>
#include <wiringPi.h>

int musicPin = 21;

int main()
{
	// The wiringPiSetup() function initialiazes the library.  Without this command, the program does nothing.
	wiringPiSetup();
//	wiringPiSetupGpio();
	printf("Set selected gpio pin to OUTPUT.\n");
	pinMode(musicPin, OUTPUT);
	printf("Set pin 12 HIGH and pin 1 LOW.\n");
	digitalWrite(musicPin, HIGH);
	printf("GPIO pin 12 is now set HIGH and GPIO pin 1 is set LOW.\n");	
	return 0;
}

