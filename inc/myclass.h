#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <memory>
#include <string>

class MyClass {
private:
    std::string _text;

public:
    MyClass();
    MyClass(std::string text);
    ~MyClass();
    void setText(std::string text);
    std::string getText();
    std::string getText(std::unique_ptr<MyClass> ptr);
    std::string getText(const std::shared_ptr<MyClass> ptr);
};

#endif /* MYCLASS_H */