#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H

#include "ICommand.h"
#include "Drawable.h"

class DrawCommand: public ICommand
{
public:
    DrawCommand(int x, int y, Drawable *drawable)
        : _x(x), _y(y),
          _drawable(drawable)
    {

    }

    virtual void execute() override
    {
        _drawable->draw(_x, _y);
    }
private:
    Drawable *_drawable;
    int _x, _y;
};


#endif /* DRAWCOMMAND_H */
