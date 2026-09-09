#include <globaldefs.h>

struct FlagWord020466f4 {
    unsigned int flags;
};

// Clears bits in the 32-bit flag word at offset 0 of its argument. The body is generic, but all 99
// call sites in the ROM hand it the global word at data_02114e04, reached through the getter at
// 0x020d6c00, and the same holds for the siblings that set (0x020466e4) and test (0x02046708) bits
// in it; no data word anywhere points at these, so there are no indirect callers.
extern "C" ARM void ClearGlobalStateFlags(struct FlagWord020466f4* word, unsigned int mask) {
    word->flags &= ~mask;
}
