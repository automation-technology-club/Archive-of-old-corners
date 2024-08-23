/* Winch01Stop.c */
/* Pins 0 & 1 control Winch01. 7/12/16 */
/* This program sets both pin 0 & pin 1 LOW. */

#include <stdio.h>
#include <wiringPi.h>

int winchPin0 = 6;
int winchPin1 = 7;

int main()
{
	// The wiringPiSetup() function initialiazes the library.  Without this command, the program does nothing.
	wiringPiSetup();
//	wiringPiSetupGpio();
	printf("Set winchPin0 & winchPin1 to OUTPUT\n");
	pinMode(winchPin0, OUTPUT);
	pinMode(winchPin1, OUTPUT);
	printf("Set winchPin0 & winchPin1 LOW\n");
	digitalWrite(winchPin0, LOW);
	digitalWrite(winchPin1, LOW);
	printf("winchPin0 & winchPin1 are now set LOW\n");	
	return 0;
}

