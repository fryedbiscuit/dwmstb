#include <stdio.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <X11/Xlib.h>

#include "dwmstb.h"

int main() {
	char buffer[6] = {0};

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
		get_clock((char*) &buffer);
		XStoreName(dpy, root, buffer);
		XFlush(dpy);
		// usleep(100000);
		sleep(31);
	}

	XCloseDisplay(dpy);
}
