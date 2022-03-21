// This is a rather small sample X program that is here
// just to let me verify that I can compile something. When I
// was first writing it I looked on the web and in the X11 documentation
// and the most helpful code snippet I found was on www.rosettacode.org.
// The code here may have moved on far enough that it is not merely a copy
// of what I found there, but I will still express my thanks here!

// I think that "Hello World" scale programs perhaps barely need explicit
// licenses, since their contents are so much defined by the requirement of
// functionality. however anything I have put here I make available to others
// under the modified BSD license.

//                                         Arthur Norman, April 2009

// $Id: window.cpp 5181 2019-11-01 17:29:32Z arthurcnorman $

#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#error This file needs "config.h"
#endif

#ifdef WIN32

#include <windows.h>
#include <cstdio>

void showwindow()
{   MessageBox(NULL, "Arthur", "Sample Window", MB_OK);
}

#else // WIN32 vs X11

#include <X11/Xlib.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "libwindow.h"

void showwindow()
{   Display *disp = XOpenDisplay(NULL);
    int screen, width, height;
    unsigned long black, white;
    Window root, window;
    GC gc;
//-    Font font;
    XEvent event;

    if (disp == NULL)
    {   std::fprintf(stderr, "Unable to access default display\n");
        std::exit(1);
    }

// Now I have a display to draw on extract all the information from it that
// I am liable to need later on.
    screen = DefaultScreen(disp);
    width = DisplayWidth(disp, screen);
    height = DisplayHeight(disp, screen);
    black = BlackPixel(disp, screen);
    white = WhitePixel(disp, screen);
    root = RootWindow(disp, screen);
    gc = DefaultGC(disp, screen);

    std::printf("Screen is %d by %d\n", width, height);
    window = XCreateSimpleWindow(disp, root,
                                 width/3, height/3, width/3, height/3,
                                 1, black, white);
    XSelectInput(disp, window, ExposureMask);
// I will now use whatever font the system thinks it has as a default. When I
// use the commented out code some systems fail to find a font that matches
// even given all the wildcards!
//- // Try for ANY 18 point font!
//-     font = XLoadFont(disp, "-*-*-*-*-*-*-*-180-*-*");
//-     XSetFont(disp, gc, font);
    Atom wmDeleteMessage = XInternAtom(disp, "WM_DELETE_WINDOW", 0);
    XSetWMProtocols(disp, window, &wmDeleteMessage, 1);
    XMapWindow(disp, window);
    XMoveWindow(disp, window, width/3, height/3);

    for (;;)
    {   XNextEvent(disp, &event);
        switch (event.type)
        {   case Expose:
                XDrawString(disp, window, gc, width/6, height/6, "Arthur", 6);
                continue;
            case ClientMessage:
                printf("Window being closed\n");
                break;
            default:
                continue;
        }
        break;
    }

    XCloseDisplay(disp);
}

#endif // X11

// end of window.cpp

