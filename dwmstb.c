#include <stdio.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <signal.h>
#include <X11/Xlib.h>
#include <strings.h>

#include "dwmstb.h"


int main() {
	char clock[10] = {0};
	char buffer[30] = {0};

	// Close on parent sigkill
	prctl(PR_SET_PDEATHSIG, SIGKILL);

	// Set up Xorg
	Display *dpy = XOpenDisplay(NULL); // NULL uses the DISPLAY env variable
	if (dpy == NULL) {
		fprintf(stderr, "Error: Could not open X display.\n");
		return 0;
	}

	Window root = DefaultRootWindow(dpy);

	while(1) {
		bzero(buffer, sizeof(buffer));

		get_clock((char*) clock);

		sprintf(buffer, "%3d%% %s", get_battery(), clock);

		XStoreName(dpy, root, buffer);
		XFlush(dpy);

		usleep(500000);
	}

	XCloseDisplay(dpy);
}
