#ifndef DRAWCANVAS_H
#define DRAWCANVAS_H

#include "Drawable.h"
#include "MacroCommand.h"
#include <iostream>

class DrawCanvas: public Drawable
{
public:
    DrawCanvas(MacroCommand *macro) : _macro(macro) {}
    ~DrawCanvas() {}

    virtual void draw(int x, int y) override
    {
        std::cout << __FUNCTION__ << " " << x << " " << y << std::endl;
    }

    void paint()
    {
        _macro->execute();
    }
private:
    MacroCommand *_macro;
};

#endif /* DRAWCANVAS_H */
