#include "command_interpreter.h"

char modes[9][30] = {"Manual mode","Auto mode","Going forward","Going backwards",
		"Turning half right","Turning half left","Turning right","Turning left","Print voltage"};

char commands[9][20] = {"Manual","Auto","Go forward","Turn around","Turn 45° right","Turn 45° left",
		"Turn 90° right","Turn 90° left","Print voltage"};


void print_received_command(int command){
	switch(command){
	case 0:
		printf("%s\n",modes[command]);
		break;
	case 1:
			printf("%s\n",modes[command]);
			break;
	case 2:
			printf("%s\n",modes[command]);
			break;
	case 3:
			printf("%s\n",modes[command]);
			break;
	case 4:
			printf("%s\n",modes[command]);
			break;
	case 5:
			printf("%s\n",modes[command]);
			break;
	case 6:
			printf("%s\n",modes[command]);
			break;
	case 7:
			printf("%s\n",modes[command]);
			break;
	case 8:
			printf("%s\n",modes[command]);
			break;
	}
}

void print_available_commands(){
	int i;
	for(i=0;i<MODES_SIZE;i++){
		printf("Press %d for %s\n",i,commands[i]);
	}
}
