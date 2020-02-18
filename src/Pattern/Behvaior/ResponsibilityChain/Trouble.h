#ifndef TROUBLE_H
#define TROUBLE_H

#include <string>

class Trouble
{
public:
    Trouble(int number) : _number(number) {}
    ~Trouble() {}

    int get_number()
    {
        return _number;
    }

    std::string to_string() const
    {
        return "[ Trouble " + std::to_string(_number) + " ]";
    }

private:
    int _number;
};

#endif /* TROUBLE_H */
