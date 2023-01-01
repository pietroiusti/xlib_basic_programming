#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    Display *display;

    display = XOpenDisplay(0);

    if (display == NULL)
    {
        fprintf(stderr, "Cannot connect to X server %c\n", 0);
        exit(-1);
    }

    XCloseDisplay(display);

    return 0;
}

