

#include <stdio.h>
#include <wiringPi.h>


int main(){

//      The wiringPiSetup() function initialiazes the library.  Without this command, the program does nothing.
        wiringPiSetup();
//      wiringPiSetupGpio();

	printf("flag 01\n");	

	pinMode(1, OUTPUT);
	printf("flag 01a\n");	

	system("pkill Pin01GPIO;");
	printf("flag 02\n");	
	pinMode(1, OUTPUT);
	printf("flag 03\n");	
	digitalWrite(1, LOW);
	printf("flag 04\n");	
	return 0;
}


