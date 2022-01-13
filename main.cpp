#include "bts.h"
#include <cxxopts.hpp>
#include <iostream>
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
    case 0:
        PLOG_INFO << "Binary Search:";
        PLOG_INFO << " index: " << binarySearchRun(size);
        break;
    default:
        break;
    }

    return 0;
}
