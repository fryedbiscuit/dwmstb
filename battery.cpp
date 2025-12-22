#include <cstdio>
#include <cstdlib>
#include <cstring>

// Android needs json library
#ifdef __ANDROID__
#include "inc/json.hpp"
using json = nlohmann::json;
#endif

extern "C" void add_battery(char* buffer){
	const char* battery 	= "\U0001F50B";
	const char* low_battery = "\U0001FAAB";
	const char* lightning 	= "\u26A1";

	char newbuffer[10];
	bool charging = false;
	bool full_charging = false;
	int percentage;
	FILE* file = NULL;

#ifndef __ANDROID__
	char status[20];

	// Get current capacity
	file = fopen("/sys/class/power_supply/BAT1/capacity","r");
	fscanf(file,"%d",&percentage);
	fclose(file);

	// Get charging status
	file = fopen("/sys/class/power_supply/BAT1/status","r");
	fscanf(file,"%s",&status);
	fclose(file);

	file = NULL;

	if (strcmp(status,"Discharging") == 0) {
		charging = false;
		full_charging = false;
	} else if (strcmp(status, "Charging") == 0) {
		charging = true
		full_charging = false;
	} else {
		charging = true;
		full_charging = true;
	}
#else
	file = popen("termux-battery-status","r");
	json batt = json::parse(file);
	pclose(file);
	percentage = (int)batt["percentage"];

	if(batt["plugged"] == "PLUGGED") {
		charging = true;
		if (percentage == 100) full_charging = true;
	}
#endif

	// Printing logic
	if (full_charging) {
		sprintf(newbuffer, " ----%s", lightning);
	} else
	if (charging) {
		sprintf(newbuffer, " %3d%%%s",percentage, lightning);
	} else
	if (percentage > 30) {
		sprintf(newbuffer, " %3d%%%s",percentage, battery);
	} else {
		sprintf(newbuffer, " %3d%%%s",percentage, low_battery);
	}
	strcat(buffer, newbuffer);
}
