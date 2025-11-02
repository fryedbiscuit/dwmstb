#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h> // For exit()

int set_root_name(char *buffer) {

    // Open a connection to the X server
    Display *dpy = XOpenDisplay(NULL); // NULL uses the DISPLAY env variable
    if (dpy == NULL) {
        fprintf(stderr, "Error: Could not open X display.\n");
        return 0;
    }

    // 3. Get the root window
    Window root = DefaultRootWindow(dpy);

    // 4. Set the WM_NAME property
    XStoreName(dpy, root, buffer);

    // 5. Flush the request buffer to ensure the server receives it
    XFlush(dpy);

    // 6. Close the connection
    XCloseDisplay(dpy);

    return 1;
}

