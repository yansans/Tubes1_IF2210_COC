#include "../Double.hpp"
#include "../Half.hpp"
#include "../Next.hpp"
#include "../CommandList.hpp"
#include <assert.h>

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

    /* Test CommandList */
    pts = 4;
    try {
        CommandList::execute("doUBle", pts, name);
        assert(pts == 8LL);
        CommandList::execute("HalF", pts, name);
        assert(pts == 4LL);
        CommandList::execute("NEXT", pts, name);
        assert(pts == 4LL);
        CommandList::execute("Triple", pts, name);
    }
    catch (exception &e) {
        cerr << e.what() << endl;
    }
    

}