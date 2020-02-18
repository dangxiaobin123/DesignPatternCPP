#ifndef BRIDGE_COUNT_DISPLAY_H
#define BRIDGE_COUNT_DISPLAY_H

#include "Display.h"

class CountDisplay: public Display
{
public:
    using Display::Display;
    void multi_display(unsigned int count) {
        open();
        for(int i = 0; i<count; i++) {
            print();
        }
        close();
    }
};

#endif