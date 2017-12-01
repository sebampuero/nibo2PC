/**
 * @file		command_interpreter.h
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		Header file for interpreting nibo commands
 */
#include <stdio.h>

//define size of available nibo modes
#define MODES_SIZE 9

/**
 * @brief Prints the received command from nibo
 * @param command the received command
 */
void print_received_command(int command);

/*
 * @brief Print available commands to send to nibo
 */
void print_available_commands();
