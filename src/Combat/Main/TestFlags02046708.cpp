#include <globaldefs.h>

struct FlagWord02046708 {
    unsigned int flags;
};

// USA: func_02046708
ARM int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask) {
    return (word->flags & mask) != 0;
}
