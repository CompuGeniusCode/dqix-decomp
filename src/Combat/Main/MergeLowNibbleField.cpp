#include <globaldefs.h>

struct MergeLowNibbleField020d76fc {
    unsigned char pad[0xa24];
    unsigned short src;
    unsigned short dst;
};

// USA: func_020d76fc
ARM void MergeLowNibbleField(struct MergeLowNibbleField020d76fc* s) {
    s->dst |= (unsigned short)(s->src & 0xf);
}
