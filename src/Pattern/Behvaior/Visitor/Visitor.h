#ifndef VISITOR_H
#define VISITOR_H

class File;
class Directory;

class Visitor
{
public:
    virtual ~Visitor(){};
    virtual void visit(File *) = 0;
    virtual void visit(Directory *) = 0;
};

#endif /* VISITOR_H */
