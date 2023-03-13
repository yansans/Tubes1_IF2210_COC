#include "../Double.hpp"
#include "../Half.hpp"
#include "../Next.hpp"

int main() {
    Command *doub = new Double;
    Command *half = new Half;
    Command *next = new Next;

    std::string name = "Geter Priffin";

    long long pts = 1;
    half->execute(pts, name);
    doub->execute(pts, name);
    next->execute(pts, name);
    half->execute(pts, name);
}