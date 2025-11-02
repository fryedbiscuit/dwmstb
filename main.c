#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TRUE 1

void add_clock(char * buffer);
int set_root_name(char* buffer);

int main() {
	int i = 0;
	while(TRUE) {
		char* buffer = calloc(100,sizeof(char));
			add_clock(buffer);
			set_root_name(buffer);
			printf("\e[1K\r%s", buffer);
		free(buffer);
		sleep(10);
	}
}
