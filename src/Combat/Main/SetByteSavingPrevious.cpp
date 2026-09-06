#include <globaldefs.h>

struct Foo02033b58 {
    char pad0[0xbe];
    unsigned char cur;
    unsigned char prev;
};

// USA: func_02033b58
ARM void SetByteSavingPrevious(struct Foo02033b58* p, unsigned char v) {
    p->prev = p->cur;
    p->cur = v;
}
