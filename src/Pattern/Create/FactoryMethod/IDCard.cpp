#include "IDCard.h"

IDCard::IDCard(const std::string &owner)
	:_owner(owner)
{
    //TODO
}

void IDCard::use()
{
    std::cout<<"use idcard with owner "<<_owner<<std::endl;
}

