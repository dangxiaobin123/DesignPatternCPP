#ifndef MESSAGE_H
#define MESSAGE_H

class Message
{
public:
    virtual ~Message() {}

    virtual void foo() = 0;
};

#endif /* MESSAGE_H */
