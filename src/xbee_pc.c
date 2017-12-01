/**
 * @file		xbee_pc.c
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		Library for wireless communication from pc
 */
#include "xbee_pc.h"

#include "command_interpreter.h"

char buf[1];
//pointe[d on the opened serial device
int fd;
//to save the count of chars received
int res;
//to save the chars which are typed into the console
int ch;
struct termios old_termios;
struct termios new_termios;

int init(){
		//opens the serial port
		fd = open(dev, O_RDWR | O_NOCTTY);
		//if the selected serial port is not found
		if (fd < 0) {
			fprintf(stderr, "error, counldn't open file %s\n", dev);
			return 0;
		}
		//returns an integer that either indicates success or failure of the prot opening
		if (tcgetattr(fd, &old_termios) != 0) {
			fprintf(stderr, "tcgetattr(fd, &old_termios) failed: %s\n", strerror(errno));
			return 0;
		}
		//configure the serial port -> for more information: http://en.wikibooks.org/wiki/Serial_Programming/termios
		memset(&new_termios, 0, sizeof(new_termios));
		new_termios.c_iflag = IGNPAR; //ignore parity bit
		new_termios.c_oflag = 0;
		new_termios.c_cflag = CS8 | CREAD | CLOCAL | HUPCL; //sets the serial port to 8N1
		new_termios.c_lflag = 0;
		new_termios.c_cc[VINTR]    = 0;
		new_termios.c_cc[VQUIT]    = 0;
		new_termios.c_cc[VERASE]   = 0;
		new_termios.c_cc[VKILL]    = 0;
		new_termios.c_cc[VEOF]     = 4;
		new_termios.c_cc[VTIME]    = 0;
		new_termios.c_cc[VMIN]     = 1;
		new_termios.c_cc[VSWTC]    = 0;
		new_termios.c_cc[VSTART]   = 0;
		new_termios.c_cc[VSTOP]    = 0;
		new_termios.c_cc[VSUSP]    = 0;
		new_termios.c_cc[VEOL]     = 0;
		new_termios.c_cc[VREPRINT] = 0;
		new_termios.c_cc[VDISCARD] = 0;
		new_termios.c_cc[VWERASE]  = 0;
		new_termios.c_cc[VLNEXT]   = 0;
		new_termios.c_cc[VEOL2]    = 0;
		//sets the input speed of the serial interdace to 9600baud
		if (cfsetispeed(&new_termios, B9600) != 0) {
			fprintf(stderr, "cfsetispeed(&new_termios, B9600) failed: %s\n", strerror(errno));
			return 0;
		}
		//sets the output speed of the serial interdace to 9600baud
		if (cfsetospeed(&new_termios, B9600) != 0) {
			fprintf(stderr, "cfsetospeed(&new_termios, B9600) failed: %s\n", strerror(errno));
			return 0;
		}
		//sets the termios struct of the file handle fd from the options defined via the options
		if (tcsetattr(fd, TCSANOW, &new_termios) != 0) {
			fprintf(stderr, "tcsetattr(fd, TCSANOW, &new_termios) failed: %s\n", strerror(errno));
			return 0;
		}
		return 1;
}
void initialiazeNiboCom(){

}
int i;
int main(void){
	if(!init())
		return 1;
	while(1){
		printf("Listening to nibo...\n");
		res = read(fd,buf,1);
		int a = buf[0] - '0';
		print_received_command(a);
		if(a == manual){
			printf("Send a command back to nibo\n");
			print_available_commands();
			scanf(" %d",&ch);
			write(fd,&ch,1);
		}
	}
	// Before leaving, reset the old serial settings and close the serial port
	tcsetattr(fd, TCSANOW, &old_termios);
	close(fd);
	printf("Serial port closed");
	return 0;
}

