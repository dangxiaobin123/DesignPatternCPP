#ifndef MESSAGE1_H
#define MESSAGE1_H

#include "Message.h"
#include "MessageFactory.h"
#include <string>
#include <iostream>

class Message1: public Message
{
public:
    Message1()
    {
        std::cout << "message1" << std::endl;
    }

    Message1(int a) 
    {
        std::cout << "message1" << " " << std::to_string(a) << std::endl;
    }

    void foo() override
	{
		std::cout << __FUNCTION__<< " message1" << std::endl;
	}
};

REGISTER_MSG(Message1, "Message1")

#endif /* MESSAGE1_H */
