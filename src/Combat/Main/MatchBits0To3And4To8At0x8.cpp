#include <globaldefs.h>

struct BitPair020de36c {
    char pad8[8];
    unsigned int a : 4;
    unsigned int b : 5;
};

// USA: func_020de36c
ARM int MatchBits0To3And4To8At0x8(struct BitPair020de36c* obj, int a, int unused, int b) {
    return a == obj->a && b == obj->b;
}
