#include <stdio.h>
#include <time.h>

void get_clock(char* output) {
	// returns a cstring the string is exactly 5 chars long plus null

	time_t now = time(NULL);
	struct tm* local_time = localtime(&now);
	int hour = local_time->tm_hour;
	int minute = local_time->tm_min;
	int second = local_time->tm_sec;

	sprintf(output, "%02d:%02d:%02d",hour,minute,second);
}
