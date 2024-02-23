#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define FNCTLPATH "/sys/module/hid_apple/parameters/fnmode"

int getFnStatus();

void setFnStatus();

int main(){
	int fd = open(FNCTLPATH, O_RDWR);
	if (fd != -1){
		int fn_status = getFnStatus(fd);
		setFnStatus(fd, fn_status);
		close(fd);
	}
	return 0;
}

int getFnStatus(int fd){
	char buffer[1];
	lseek(fd,0,SEEK_SET);
	read(fd, buffer, 1);
	int fd_status = atoi(buffer);
	return fd_status;
}

void setFnStatus(int fd, int fd_status){
	char buffer[1];
	int new_fn_status = 0;
	if (fd_status == 2){
		new_fn_status = 1;
	} else if (fd_status == 1){
		new_fn_status = 2;
	} else {
		// set 1 as the default (on first run)
		new_fn_status = 1;
	}
	sprintf(buffer, "%d", new_fn_status);
	write(fd, buffer, sizeof(buffer));
}
