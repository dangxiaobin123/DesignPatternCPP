#ifndef ADAPTER_PAINTER_H
#define ADAPTER_PAINTER_H

class Painter
{
public:
    virtual ~Painter() {}
    virtual void print_strong() = 0;
    virtual void print_weak() = 0;
};

#endif