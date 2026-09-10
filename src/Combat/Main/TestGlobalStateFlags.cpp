#include <globaldefs.h>

struct FlagWord02046708 {
    unsigned int flags;
};

// Tests bits in the global state word at 0x02114e04. It is the read of the set/clear/test trio that
// starts at 0x020466e4, whose middle member is already named ClearGlobalStateFlags. The function
// itself takes any flag word, but every decompiled caller passes that one global; the masks they
// use are varied and what the individual bits mean is not established.
extern "C" ARM int TestGlobalStateFlags(struct FlagWord02046708* word, unsigned int mask) {
    return (word->flags & mask) != 0;
}
