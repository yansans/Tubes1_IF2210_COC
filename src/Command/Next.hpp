#ifndef __NEXT_HPP__
#define __NEXT_HPP__

#include "Command.hpp"

class Next: public Command {
    public:
    /**
     * @brief output msg.
     * 
     * @param pts 
     * @param name 
     */
    void execute(long long &pts, std::string name) override;
};

#endif