#include <globaldefs.h>

struct AlignedValueSource020309d0 {
    char pad[2];
    unsigned char n;
};

// USA: func_020309d0
ARM int ComputeAlignedValue020309d0(int unused, struct AlignedValueSource020309d0* p) {
    int x = p->n * 2;
    int c = x / 8 + (x % 8 > 0);
    int m = c + 3;
    return m + (4 - m % 4) % 4;
}
