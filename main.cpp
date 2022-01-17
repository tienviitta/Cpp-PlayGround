#include "myclass.h"
#include <cxxopts.hpp>
#include <iostream>
#include <memory>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Init.h>
#include <plog/Log.h>

// command line arguments
cxxopts::Options
    options("Cpp-PlayGround",
            "Unit Tests, Logging, The Rule of Five and Smart Pointer");

// logger formatter
static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;

int main(int argc, const char **argv) {

    // command line arguments
    // clang-format off
    options.add_options()
        ("d, debug", "Enable debugging")
        ("r, run", "Run", cxxopts::value<int>()->default_value("0"))
        ("n, size", "Size", cxxopts::value<int>()->default_value("10"))
        ("h, help", "Print usage");
    // clang-format on
    options.allow_unrecognised_options();
    auto result = options.parse(argc, argv);
    if (result.count("help"))
    {
      std::cout << options.help() << std::endl;
      exit(0);
    }
    bool debug = result["debug"].as<bool>();
    int run = result["run"].as<int>();
    int size = result["size"].as<int>();

    // logger init
    plog::Severity severity;
    if (result["debug"].as<bool>()) {
        severity = plog::Severity::debug;
    } else {
        severity = plog::Severity::info;
    }
    plog::init(severity, &consoleAppender);

    PLOG_INFO << "Cpp-PlayGround:";
    PLOG_INFO << " debug: " << debug;
    PLOG_INFO << " run: " << run;
    PLOG_INFO << " size: " << size;

    // Run
    switch (run) {
    case 0: {
        PLOG_INFO << "Smart Pointers I:";
        // create unique pointer to proprietary class
        // std::unique_ptr<MyClass> myClass1(new MyClass());
        std::unique_ptr<MyClass> myClass1 = std::make_unique<MyClass>();
        std::unique_ptr<MyClass> myClass2(new MyClass("String 2"));
        PLOG_DEBUG << myClass1->getText();
        PLOG_DEBUG << myClass2->getText();
        // call member function using ->
        myClass1->setText("String 1");
        PLOG_DEBUG << myClass1->getText();
        PLOG_DEBUG << myClass2->getText();
        // use the dereference operator *
        *myClass1 = *myClass2;
        PLOG_DEBUG << myClass1->getText();
        PLOG_DEBUG << myClass2->getText();
        // use the .get() function to retrieve a raw pointer to the object
        PLOG_INFO << " Stack addresses " << myClass1.get() << " and "
                  << myClass2.get();
        break;
    }
    case 1: {
        PLOG_INFO << "Smart Pointers II:";
        std::unique_ptr<MyClass> uniPtr0 =
            std::make_unique<MyClass>("I'm Unique");
        std::unique_ptr<MyClass> uniPtr1 =
            std::make_unique<MyClass>("I'm Unique too");
        PLOG_INFO << " uniPtr0: " << &uniPtr0 << ": " << uniPtr0->getText();
        PLOG_INFO << " uniPtr1: " << &uniPtr1 << ": " << uniPtr1->getText();
        PLOG_INFO << " move: " << uniPtr0->getText(std::move(uniPtr1));
        PLOG_INFO << " uniPtr0: " << &uniPtr0 << ": " << uniPtr0->getText();
        // Warning! Prevent segmentation fault!
        if (uniPtr1) {
            PLOG_INFO << " uniPtr1: " << &uniPtr1 << ": " << uniPtr1->getText();
        }
        break;
    }
    case 2: {
        PLOG_INFO << "Smart Pointers III:";
        std::shared_ptr<MyClass> shPtr0 =
            std::make_unique<MyClass>("I'm Shared");
        std::shared_ptr<MyClass> shPtr1 =
            std::make_unique<MyClass>("I'm Shared too");
        PLOG_INFO << " shPtr0: " << &shPtr0 << ": " << shPtr0->getText();
        PLOG_INFO << " shPtr1: " << &shPtr1 << ": " << shPtr1->getText();
        PLOG_INFO << " usage: " << shPtr0.use_count() << ", "
                  << shPtr1.use_count();
        PLOG_INFO << " copy: " << shPtr0->getText(shPtr1);
        PLOG_INFO << " usage: " << shPtr0.use_count() << ", "
                  << shPtr1.use_count();
        PLOG_INFO << " shPtr0: " << &shPtr0 << ": " << shPtr0->getText();
        // Warning! Prevent segmentation fault!
        if (shPtr1) {
            PLOG_INFO << " shPtr1: " << &shPtr1 << ": " << shPtr1->getText();
        }
        break;
    }
    default:
        break;
    }

    return 0;
}
