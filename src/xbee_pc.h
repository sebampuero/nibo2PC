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
#include <stdlib.h>
#include <stdint.h>

#define dev "/dev/ttyUSB0"

enum modes {manual, autonom, forward, backwards, half_right, half_left, right, left, voltage };

int init();

void initializeNiboCom();
