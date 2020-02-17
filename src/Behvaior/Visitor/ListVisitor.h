#ifndef LISTVISITOR_H
#define LISTVISITOR_H

#include "Visitor.h"
#include <string>
#include <iostream>
#include "File.h"
#include "Directory.h"

class ListVisitor : public Visitor
{
public:
    virtual void visit(File *file) override 
    {
        std::cout << m_currentDir  << "/" << file->get_name()  << " " << file->get_size() << std::endl;
    }
    virtual void visit(Directory *dir) override
    {
        std::cout << m_currentDir  << "/" << dir->get_name() << " " << dir->get_size() << std::endl;
        std::string saved = m_currentDir; 
        m_currentDir += "/" + dir->get_name();
        auto entryList = dir->get_entry_list();
        for (auto it: entryList)
        {
            it->accept(this);
        }
        m_currentDir = saved;
    }
private:
    std::string m_currentDir;
};

#endif /* LISTVISITOR_H */
