#ifndef IDISPLAY_H
#define IDISPLAY_H

class IDisplay
{
public:
    IDisplay(/* args */) {}
    virtual ~IDisplay() {}

#pragma region Interface

    virtual void open() = 0;

    virtual void close() = 0;
    
    virtual void print() = 0;
#pragma endregion

    void display()
    {
        open();
        print();
        close();
    }
};

#endif /* IDISPLAY_H */
