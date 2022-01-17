#include "myclass.h"
#include <iostream>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Init.h>
#include <plog/Log.h>

MyClass::MyClass() { PLOG_DEBUG << "MyClass (" << this << "): Constructor!"; }
MyClass::MyClass(std::string text) {
    PLOG_DEBUG << "MyClass (" << this << "): Constructor(std::string)!";
    _text = text;
}
MyClass::~MyClass() {
    PLOG_DEBUG << "MyClass (" << this << "): Destructor!";
    PLOG_DEBUG << _text << " destroyed";
}
void MyClass::setText(std::string text) { _text = text; }
std::string MyClass::getText() { return _text; }
std::string MyClass::getText(std::unique_ptr<MyClass> ptr) {
    return ptr->getText();
}
std::string MyClass::getText(const std::shared_ptr<MyClass> ptr) {
    PLOG_DEBUG << "usage: " << ptr.use_count();
    return ptr->getText();
}