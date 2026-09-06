#include <globaldefs.h>

ARM int TestSubsFusion(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    int shift = 0x41e - (int)(a >> 20);
    if (shift <= 0) goto L;
    return shift + b + c + d + 5 + a*3;
L:
    return 1;
}
