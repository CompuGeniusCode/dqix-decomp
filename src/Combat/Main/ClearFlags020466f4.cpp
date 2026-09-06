#include <globaldefs.h>

struct FlagWord020466f4 {
    unsigned int flags;
};

// USA: func_020466f4
ARM void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask) {
    word->flags &= ~mask;
}
