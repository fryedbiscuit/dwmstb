#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TRUE 1

extern void add_clock(char * buffer);

#ifdef TEST
void setname(char* buffer){
	printf("\x1B[1K\r");
	printf("{%s}",buffer);
	fflush(stdout);
}
#else
int setname(char* str) {
	char cmd[1000] = "xsetroot -name \"";
	strcat(cmd, str);
	strcat(cmd, "\"");
	return system(cmd);
}

#endif
int main() {
	int i = 0;
	while(TRUE) {
		sleep(10);
		char* buffer = calloc(100,sizeof(char));
			add_clock(buffer);
			setname(buffer);
		free(buffer);
	}
}
