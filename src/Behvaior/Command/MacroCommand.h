#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "ICommand.h"
#include <vector>

class MacroCommand: public ICommand
{
public:
    MacroCommand(/* args */) {}
    ~MacroCommand()
    {
        clear();
    }

    virtual void execute() override
    {
        for (auto cmd : _command_list) {
            cmd->execute();
        }
    }

    void add_command(ICommand *cmd)
    {
        _command_list.push_back(cmd);
    }

    void clear()
    {
        for (auto cmd : _command_list) {
            delete cmd;
            cmd = nullptr;
        }
        _command_list.clear();
    }

    void undo()
    {
        if (!_command_list.empty()) {
            auto cmd = _command_list.back();
            delete cmd;
            _command_list.pop_back();
        }
    }
private:
    std::vector<ICommand *> _command_list;
};

#endif /* MACROCOMMAND_H */
