/**
 * @file		xbee_pc.h
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		Header file Library for wireless communication from pc
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define dev "/dev/ttyUSB3"
#define nibo_manual 1
#define nibo_auto 2
#define nibo_forward 3
#define nibo_backward 4
#define nibo_half_right 5
#define nibo_half_left 6
#define nibo_right 7
#define nibo_left 8
#define nibo_print_voltage 9

int init();

void initializeNiboCom();
