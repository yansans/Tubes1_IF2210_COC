#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <string.h>
#include <iostream>

class Command {
    public:
    /**
     * @brief Change point and output msg depending on command.
     * 
     * @param pts 
     * @param name player name
     */
    virtual void execute(long long &pts, std::string name) = 0;
};

#endif