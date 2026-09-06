#include <globaldefs.h>

struct S020535f4 {
    char pad[0x184];
    unsigned char counter;
};

// USA: func_020535f4
ARM void IncrementByteAt0x184(struct S020535f4* p) {
    p->counter++;
}
