#include <stdio.h>
#include <string.h>
void add_volume(char* buffer){
	const char volume_mute[]   = "\U0001F507";
	const char volume_low[]    = "\U0001F508";
	const char volume_medium[] = "\U0001F509";
	const char volume_high[]   = "\U0001F50A";

	char newbuffer[10]; 
	char mute;
	int volume;

	// Get mute status
	FILE* pa_mute = popen("pamixer --get-mute", "r");
	fscanf(pa_mute,"%c",&mute);
	pclose(pa_mute);

	// Get current volume
	FILE* pa_vol = popen("pamixer --get-volume", "r");
	fscanf(pa_vol,"%d", &volume);

	if (mute == 't'){
		sprintf(newbuffer, "(%2d%%)%s ",volume, mute);
	} else {
		if (volume < 30){
			sprintf(newbuffer, "%3d%%%s ",volume, volume_low);
		} else if (volume < 60) {
			sprintf(newbuffer, "%3d%%%s ",volume, volume_medium);
		} else if (volume >= 60) {
			sprintf(newbuffer, "%3d%%%s ",volume, volume_high);
		}
	}
	strcat(buffer, newbuffer);
}
