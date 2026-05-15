#include <stdio.h>

#ifdef __ANDROID__
int get_battery(void) {
	char line[100];
	int charge;
	char* prefix = "  \"percentage\"";

	FILE* p = popen("termux-battery-status","r");

	// Read line and compare
	while(fgets(line,sizeof(line),p)) {
		if (strncmp(line, prefix, strlen(prefix)) == 0) {
			sscanf(line, "  \"percentage\": %d,", &charge);
		}
	}

	pclose(p);

	return charge;
}
#else
int get_battery(void) {
	int charge;

	// Get current capacity
	FILE* file = fopen("/sys/class/power_supply/BAT1/capacity","r");
	fscanf(file,"%d",&charge);
	fclose(file);
	
	return charge;
}
#endif
