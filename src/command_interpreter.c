/**
 * @file		command_interpreter.c
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		Library for interpreting nibo commands
 */
#include "command_interpreter.h"

//Modes which the nibo can go into
char modes[9][30] = {"Manual mode","Auto mode","Going forward","Going backwards",
		"Turning half right","Turning half left","Turning right","Turning left","Print voltage"};

//Array of commands that can be sent to the nibo
char commands[9][20] = {"Manual","Auto","Go forward","Turn around","Turn 45° right","Turn 45° left",
		"Turn 90° right","Turn 90° left","Print voltage"};

/**
 * @brief Prints the received command from nibo
 * @param command the received command
 */
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
/*
 * @brief Print available commands to send to nibo
 */
void print_available_commands(){
	int i;
	for(i=0;i<MODES_SIZE;i++){
		printf("Press %d for %s\n",i,commands[i]);
	}
}
