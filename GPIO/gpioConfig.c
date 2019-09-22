#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INPUT 0
#define OUTPUT 1

//----Global Variables----//
int arquive = 0;
char buffer[3];
char path[35];
//-----------------------//


void export_gpio(int pin){
	arquive = 0;       
	arquive = open("/sys/class/gpio/export", O_WRONLY);
	if(arquive == -1){
		printf("Error in open export file\n");
	}
	
	snprintf(buffer, 3, "%d", pin);
	if(write(arquive, buffer,3) == -1){
		close(arquive);
	}

	close(arquive);
}

void pinMode(int pin, int direction){
	
	arquive=0;
	snprintf(path, 35,"/sys/class/gpio/gpio%d/direction", pin);
	arquive = open(path, O_WRONLY);
	
	if(arquive == -1)
		printf("Error to access direction file.\n");
	
	snprintf(buffer, 3, "%d", pin);
	if(write(arquive, ((direction == INPUT)?"in":"out"), 3) == -1){
		close(arquive);
	}

	close(arquive);
}

void pinWrite(int pin, int value){
	arquive = 0;
	snprintf(path, 35, "/sys/class/gpio/gpio%d/value", pin);

	arquive = open(path, O_WRONLY);
	if(arquive == -1)
		printf("Error to acces value file.\n");
	if(write(arquive, ((value == 1)?"1":"0"), 1) == -1)
		close(arquive);
	close(arquive);
}

