#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long fsize(FILE* f){
	long size,cur;

	cur = ftell(f);
	fseek(f,0,SEEK_END);
	size = ftell(f);
	fseek(f,cur,SEEK_SET);
	
	return size;
}

void add_battery(char* buffer){
	const char battery[] = "\U0001F50B";
	const char low_battery[] = "\U0001FAAB";
	const char lightning[] = "\u26A1";
	char* emoji = NULL;

	char newbuffer[10];
	char status[20];
	int percentage;
	FILE* f = NULL;

	// Get current capacity
	f = fopen("/sys/class/power_supply/BAT1/capacity","r");
	fscanf(f,"%d",&percentage);
	fclose(f);

	// Get charging status
	f = fopen("/sys/class/power_supply/BAT1/status","r");
	fscanf(f,"%s",&status);
	fclose(f);

	if (strcmp(status,"Discharging") == 0) {
		if (percentage < 30){
			sprintf(newbuffer, " %02d%%%s",percentage, low_battery);
		} else {
			sprintf(newbuffer, " %02d%%%s",percentage, battery);
		}
	} else if (strcmp(status, "Charging") == 0) {
		sprintf(newbuffer, " %02d%%%s",percentage, lightning);
	} else {
		sprintf(newbuffer, " ---%s", lightning);
	}

	strcat(buffer, newbuffer);
}
