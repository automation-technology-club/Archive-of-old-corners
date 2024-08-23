/* This program stops the GPIO scan. */

#include <stdio.h>
#include <wiringPi.h>

int i;


int main(){

//	The wiringPiSetup() function initialiazes the library.  Without this command, the program does nothing.
        wiringPiSetup();
//      wiringPiSetupGpio();

	printf("flag01\n");
	system("pkill scanGPIO;");

	printf("flag02\n");
	for( i = 0; i < 7 ; i++){
	printf("flag03\n");
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
	printf("flag04\n");
	return 1;

	}

