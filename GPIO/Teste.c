#include"piGpioConfig.h"
#include <stdio.h>
#include<stdlib.h>


int main(void){

	export_gpio(16);
	pinMode(16, 1);
	pinWrite(16, 0);
	return 0;
}

