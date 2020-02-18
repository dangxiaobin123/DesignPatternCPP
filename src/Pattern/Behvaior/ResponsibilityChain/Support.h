#ifndef SUPPORT_H
#define SUPPORT_H

#include "Trouble.h"
#include <iostream>

class Support
{
public:
    Support(const std::string &name) : _name(name) {}
    virtual ~Support() {}

    Support *set_next(Support *next)
    {
        _next = next;
        return _next;
    }

    std::string to_string() const
    {
        return "[" + _name + "]";
    }

    void support(Trouble *trouble)
    {
        if (resolve(trouble)) {
            done(trouble);
        } else if (_next) {
            _next->support(trouble);
        } else {
            fail(trouble);
        }
    }

    virtual bool resolve(Trouble *trouble) = 0;
protected:
    void done(Trouble *trouble)
    {
        std::cout << trouble->to_string() << " is solved by " << to_string() << std::endl;
    }

    void fail(Trouble *trouble)
    {
        std::cout << trouble->to_string() << " cannot be resolved." << std::endl;
    }

private:
    std::string _name;
    Support *_next;
};

#endif /* SUPPORT_H */
