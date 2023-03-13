#include "Half.hpp"

void Half::execute(long long &pts, std::string name)
{
    std::cout << name << " melakukan HALF! ";
    if (pts == 1LL) {
        std::cout << "Sayangnya poin hadiah sudah bernilai "
                  << "1. Poin hadiah tidak berubah.. Giliran dilanjut!" << std::endl;
    }
    else {
        std::cout << "Poin hadiah turun dari "
                  << pts << " menjadi " << (pts / 2) << "!" << std::endl;
        pts /= 2;
    }
}
