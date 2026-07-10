#include <globaldefs.h>

extern "C" int func_020d6884(int, int, void*, int);

// USA: func_020d6830
ARM int TestFlagBitsAndDispatch020d6884(int a, unsigned short* b, int c) {
    unsigned short m0 = b[0];
    unsigned short m2 = b[1];
    int mask = 1 << c;
    if (a == 0) return 0;
    if (b == NULL) return 0;
    if ((m0 & mask) == 0) return 0;
    if ((m2 & mask) == 0) return 0;
    return func_020d6884(a, m0, (unsigned short*)((char*)b + 4), c);
}
