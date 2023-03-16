#ifndef __COMMANDLIST_HPP__
#define __COMMANDLIST_HPP__

#include <map>
#include <algorithm>

#include "Double.hpp"
#include "Half.hpp"
#include "Next.hpp"
#include "../Exception/Exception.h"

class CommandList
{
private:
    static std::map<std::string, Command *> cmdList;

public:
    /**
     * @brief execute command
     * @exception InvalidCommand
     *
     * @param commandString string command, case insensitive
     * @param points current game points to be changed
     * @param name
     */
    static void execute(std::string commandString, long long &points, std::string name);
};

#endif