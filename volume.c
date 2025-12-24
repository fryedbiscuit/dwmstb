#include <stdio.h>
#include <string.h>
void add_volume(char* buffer){
	const char* volume_mute   = "\U0001F507";
	const char* volume_low    = "\U0001F508";
	const char* volume_medium = "\U0001F509";
	const char* volume_high   = "\U0001F50A";

	char newbuffer[10]; 
	FILE* pa = NULL;
	char mute;
	int volume;

	// Get mute status
	pa = popen("pactl get-sink-mute @DEFAULT_SINK@", "r");
	fscanf(pa,"%*s %c",&mute);
	pclose(pa);

	// Get current volume
	pa = popen("pactl get-sink-volume @DEFAULT_SINK@", "r");
	fscanf(pa,"%*s %*s %*s %*s %d", &volume);
	pclose(pa);

	if (mute == 'y'){
		sprintf(newbuffer, "%3d%%%s ",volume, volume_mute);
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
