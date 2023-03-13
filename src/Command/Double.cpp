#include "Double.hpp"

void Double::execute(long long &pts, std::string name)
{
    std::cout << name << " melakukan DOUBLE! Poin hadiah naik dari "
              << pts << " menjadi " << (pts * 2) << "!" << std::endl;
    pts *= 2;
}
