#ifndef MESSAGEFACTORY_H
#define MESSAGEFACTORY_H

#include <map>
#include <string>
#include <functional>
#include <memory>

class Message;

class Factory
{
public:
    template<class T>
    struct register_t {
        register_t(const std::string &key)
        {
            Factory::get()._map.emplace(key, [] {return new T();});
        }

        template<class... Args>
        register_t(const std::string &key, Args&&... args)
        {
            Factory::get()._map.emplace(key, [&] {
                return new T(args...);
            });
        }
    };

    static Message *produce(const std::string &key)
    {
        if (!_map.count(key))
            throw std::invalid_argument("the message key is not exist!");
        return _map[key]();
    }

    static std::unique_ptr<Message> produce_unique(const std::string &key)
    {
        return std::unique_ptr<Message>(produce(key));
    }

    static std::shared_ptr<Message> produce_shared(const std::string &key)
    {
        return std::shared_ptr<Message>(produce(key));
    }
private:
    Factory() {};
    Factory(const Factory &) = delete;
    Factory &operator=(const Factory &) = delete;

    static Factory &get()
    {
        static Factory ins;
        return ins;
    }

    static std::map<std::string, std::function<Message*()>> _map;
};

std::map < std::string, std::function<Message*()>> Factory::_map;

#define REGISTER_MSG_VNAME(T) reg_msg_##T##_
#define REGISTER_MSG(T, key, ...) static Factory::register_t<T> REGISTER_MSG_VNAME(T)(key, ##__VA_ARGS__);

#endif /* MESSAGEFACTORY_H */
