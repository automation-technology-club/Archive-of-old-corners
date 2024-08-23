/* MusicOff.c */
/* MusicOff is controlled by GPIO pins 21. 7/12/16 */
/* This program sets GPIO pin 21 HIGH, GPIO pin 1 LOW and returns control to the calling script. 7/12/16 */

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
	printf("Set pin 21 LOW.\n");
	digitalWrite(musicPin, LOW);
	printf("GPIO pin 21 is now set LOW.\n");	
	return 0;
}

