#ifndef __HALF_HPP__
#define __HALF_HPP__

#include "command.hpp"

class Half: public Command {
    public:
    /**
     * @brief Half point and output msg.
     * 
     * @param pts 
     * @param name player name
     */
    void execute(long long &pts, std::string name) override;
};

#endif