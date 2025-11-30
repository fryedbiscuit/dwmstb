#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/prctl.h>
#include <signal.h>

#define TRUE 1

void add_clock(char * buffer);
void add_battery(char * buffer);
void add_volume(char * buffer);
int set_root_name(char* buffer);

int main() {
	prctl(PR_SET_PDEATHSIG, SIGKILL);
	int i = 0;
	while(TRUE) {
		char* buffer = (char*) calloc(100,sizeof(char));
			add_clock(buffer);
			add_battery(buffer);
			add_volume(buffer);
			set_root_name(buffer);
			printf("\e[1K\r%s", buffer);
			fflush(stdout);
		free(buffer);
		sleep(2);
	}
}
