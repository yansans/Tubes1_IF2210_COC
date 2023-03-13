#include "CommandList.hpp"

std::map<std::string, Command*> CommandList::cmdList = {
    {"double", new Double()},
    {"half", new Half()},
    {"next", new Next()}
};

void CommandList::execute(std::string commandString, long long &points, std::string name)
{
    std::string lowerCommandString;
    transform(commandString.begin(), commandString.end(), std::back_inserter(lowerCommandString), 
        [](char c) {
            return c + (('A' <= c && c <= 'Z') ? 32 : 0);
        }
    );
    std::cout << lowerCommandString << std::endl;
    
    if (cmdList.find(lowerCommandString) == cmdList.end()) {
        throw InvalidCommand();
    }
    cmdList[lowerCommandString]->execute(points, name);
}
