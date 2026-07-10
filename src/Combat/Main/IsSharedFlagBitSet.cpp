#include <globaldefs.h>

struct SharedFlagBlock020cae70 {
    char pad[0x388];
    unsigned int flags[256];
};

// USA: func_020cae70
ARM int IsSharedFlagBitSet(int bit, int index) {
    struct SharedFlagBlock020cae70* block = (struct SharedFlagBlock020cae70*)0x27ffc00;
    return (block->flags[index] & (1 << bit)) != 0;
}
