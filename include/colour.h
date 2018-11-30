#pragma once

#include <string>
#include <sstream>
#include <iostream>

typedef enum {
    CONSOLE_COLOUR_FG_DEFAULT = 39,
    CONSOLE_COLOUR_FG_BLACK = 30, 
    CONSOLE_COLOUR_FG_RED = 31, 
    CONSOLE_COLOUR_FG_GREEN = 32, 
    CONSOLE_COLOUR_FG_YELLOW = 33, 
    CONSOLE_COLOUR_FG_BLUE = 34, 
    CONSOLE_COLOUR_FG_MAGENTA = 35, 
    CONSOLE_COLOUR_FG_CYAN = 36, 
    CONSOLE_COLOUR_FG_LIGHT_GRAY = 37, 
    CONSOLE_COLOUR_FG_DARK_GRAY = 90, 
    CONSOLE_COLOUR_FG_LIGHT_RED = 91, 
    CONSOLE_COLOUR_FG_LIGHT_GREEN = 92, 
    CONSOLE_COLOUR_FG_LIGHT_YELLOW = 93, 
    CONSOLE_COLOUR_FG_LIGHT_BLUE = 94, 
    CONSOLE_COLOUR_FG_LIGHT_MAGENTA = 95, 
    CONSOLE_COLOUR_FG_LIGHT_CYAN = 96, 
    CONSOLE_COLOUR_FG_WHITE = 97
} ConsoleForegroundColour;

typedef enum {
    CONSOLE_COLOUR_BG_RED = 41, 
    CONSOLE_COLOUR_BG_GREEN = 42, 
    CONSOLE_COLOUR_BG_BLUE = 44, 
    CONSOLE_COLOUR_BG_DEFAULT = 49
} ConsoleBackgroundColour;

class Colour {
public:
    template<class T, class D>
    static std::string getColouredText(T colour, D text) {
        std::stringstream output;
        output << "\033[" << colour << "m" << text;
        output << "\033[" << CONSOLE_COLOUR_BG_DEFAULT << "m";
        output << "\033[" << CONSOLE_COLOUR_FG_DEFAULT << "m";
        return output.str();
    }

    static void foregroundColour(ConsoleForegroundColour colour) {
        std::cout << "\033[" << colour << "m";
    }

    static void backgroundColour(ConsoleForegroundColour colour) {
        std::cout << "\033[" << colour << "m";
    }

    template<class T>
    static void consoleColour(T colour) {
        std::cout << "\033[" << colour << "m";
    }
};
