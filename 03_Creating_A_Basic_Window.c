#include <X11/Xlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    Display *display;            // pointer to X Display structure.
    int screen_num;              // number of screen to place the windon on.
    Window win;                  // pointer to newly created window.
    unsigned int display_width,  
                 display_height; // height and width of the X display.
    unsigned int width, height;  // height and width of the new window.
    unsigned int win_x, win_y;   // location of the window's top-left corner.
    unsigned int win_border_width; // width of window's border.
    char *display_name = getenv("DISPLAY"); // address of the X display
    printf("%c\n", *display_name);
    
    display = XOpenDisplay(display_name);
    if (display == NULL)
    {
        fprintf(stderr, "Cannot connect to X server %c\n", 0);
        exit(-1);
    }

    // get the geometry of the default screen of our display
    screen_num = DefaultScreen(display);
    display_width = DisplayWidth(display, screen_num);
    display_height = DisplayHeight(display, screen_num);
    
    // make the new window occupy 1/9 of the screen's size.
    width = (display_width / 3);
    height = (display_height / 3);
    
    // the window should be placed at the top-left corner of the screen
    win_x = 0;
    win_y = 0;
    
    win_border_width = 2;

    /* create a simple window, as a direct child of the screen's root
       window.  Use the screen's white color as the background color
       of the window. Place the new window's top-left corner at the
       given 'x,y' coordinates. */
    win = XCreateSimpleWindow(display, RootWindow(display, screen_num),
                              win_x, win_y, width, height, win_border_width,
                              BlackPixel(display, screen_num),
                              WhitePixel(display, screen_num));    

    // make the window actually appear on the screen
    XMapWindow(display, win);
    
    // flush all pending request to the X server, and wait until they
    // are processed by the X server.
    XSync(display, False);
    
    // short delay
    sleep(5);

    // close the connection to the X server
    XCloseDisplay(display);

    return 0;
}
