#pragma once

#include <time.h>
#include <colour.h>

class Logger {
public:
    template<class T>
    static void log(T obj) {
        std::cout << getTime() << " " << obj << std::endl;
    }

    template<class T>
    static void info(T obj) {
        std::cout
            << getTime() << " [" << Colour::getColouredText(CONSOLE_COLOUR_FG_GREEN, "INFO")
            << "] " << obj << std::endl;
    }

    template<class T>
    static void warn(T obj) {
        std::cout
            << getTime() << " [" << Colour::getColouredText(CONSOLE_COLOUR_FG_LIGHT_YELLOW, "WARN")
            << "] " << obj << std::endl;
    }

    template<class T>
    static void error(T obj) {
        std::cout
            << getTime() << " [" << Colour::getColouredText(CONSOLE_COLOUR_FG_LIGHT_RED, "ERROR")
            << "] " << obj << std::endl;
    }

    template<class T>
    static void panic(T obj) {
        std::cout
            << getTime() << " [" << Colour::getColouredText(CONSOLE_COLOUR_FG_RED, "PANIC")
            << "] " << obj << std::endl;
        exit(0);
    }
private:
    static std::string getTime() {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        std::stringstream stream;
        stream                      << "["
            << tm.tm_mday           << "-"
            << tm.tm_mon + 1        << "-"
            << tm.tm_year + 1900    << " "
            << tm.tm_hour           << ":"
            << tm.tm_min            << ":"
            << tm.tm_sec            << "]";
        return stream.str();
    }
};
