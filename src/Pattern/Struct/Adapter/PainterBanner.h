#ifndef ADAPTER_PAINTER_BANNER_H
#define ADAPTER_PAINTER_BANNER_H

#include "Painter.h"
#include "Banner.h"

class PainterBanner: public Painter, public Banner
{
public:
    PainterBanner(const std::string &str):Banner(str) {}

    virtual void print_strong() override {
        show_with_paren();
    }

    virtual void print_weak() override {
        show_with_aster();
    }
};

#endif