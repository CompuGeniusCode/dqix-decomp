#include <globaldefs.h>

struct Holder021e856c {
    char pad0[0xc];
    unsigned char* inner;
};

extern struct Holder021e856c data_ov025_021ef988;

// USA: func_ov025_021e856c
ARM int SetFlag021e856c(void) {
    data_ov025_021ef988.inner[0x578] = 1;
    return 1;
}
