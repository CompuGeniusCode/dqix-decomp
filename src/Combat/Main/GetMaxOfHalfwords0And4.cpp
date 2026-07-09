#include <globaldefs.h>

struct Pair020deb08 {
    unsigned short a;
    unsigned short pad2;
    unsigned short b;
};

// USA: func_020deb08
ARM short GetMaxOfHalfwords0And4(struct Pair020deb08* obj) {
    int a = obj->a;
    int b = obj->b;
    return a > b ? a : b;
}
