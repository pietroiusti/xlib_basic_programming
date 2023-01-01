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


    int screen_num;
    int screen_width;
    int screen_height;
    Window root_window;
    unsigned long white_pixel;
    unsigned long black_pixel;
    screen_num = DefaultScreen(display);
    printf("screen_num: %d\n", screen_num);
    screen_width = DisplayWidth(display, screen_num);
    printf("screen_width: %d\n", screen_width);
    screen_height = DisplayHeight(display, screen_num);
    printf("screen_height: %d\n", screen_height);
    root_window = RootWindow(display, screen_num);
    printf("root_window: %lu\n", root_window);
    white_pixel = WhitePixel(display, screen_num);
    printf("white_pixel: %lu\n", white_pixel);
    black_pixel = BlackPixel(display, screen_num);
    printf("black_pixel: %lu\n", black_pixel);


    XCloseDisplay(display);

    return 0;
}

