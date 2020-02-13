#ifndef PROTOTYPE_PRODUCTMANAGER_H
#define PROTOTYPE_PRODUCTMANAGER_H

#include "IProduct.h"
#include <unordered_map>
#include <string>

class ProductManager
{
public:
    void registers(const std::string& name, IProduct* p) {
        _map.emplace(name, p);
    }

    IProduct *create(const std::string &name)
    {
        if (_map.count(name)) {
            return _map[name]->clone();
        }
        return nullptr;
    }
private:
    std::unordered_map<std::string, IProduct *> _map;
};

#endif
