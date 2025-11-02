#include <time.h>
#include <stdlib.h>

extern void add_clock(char * buffer) {
	time_t now = time(NULL);
	struct tm* local_time = localtime(&now);
	int hour = local_time->tm_hour;
	int minute = local_time->tm_min;

	char clock[10];
	sprintf(clock, "[%d:%d]",hour,minute);

	strcat(buffer,clock); 
}
