#ifndef ADAPTER_BANNER_PAINTER_H
#define ADAPTER_BANNER_PAINTER_H

#include "Painter.h"
#include "Banner.h"

class BannerPainter: public Painter
{
public:
    BannerPainter(const std::string &str) : _banner(str) {}

    virtual void print_strong() override
    {
        _banner.show_with_paren();
    }

    virtual void print_weak() override
    {
        _banner.show_with_aster();
    }
private:
    Banner _banner;
};

#endif