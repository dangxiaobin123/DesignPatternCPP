#ifndef DECORATOR_IDISPLAY_H
#define DECORATOR_IDISPLAY_H

#include <string>
#include <iostream>
class IDisplay
{
public:
    virtual ~IDisplay() {}
    virtual int get_rows() const = 0;
    virtual int get_columns() const = 0;
    virtual std::string get_row(int index) const = 0;

    void show()
    {
        int r = get_rows();
        for (int i = 0; i < r; i++) {
            std::cout << get_row(i) << std::endl;
        }
    }
};

#endif