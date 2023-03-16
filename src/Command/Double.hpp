#ifndef __DOUBLE_HPP__
#define __DOUBLE_HPP__

#include "Command.hpp"

class Double : public Command
{
public:
    /**
     * @brief Double point and output msg.
     *
     * @param pts
     * @param name
     */
    void execute(long long &pts, std::string name) override;
};

#endif