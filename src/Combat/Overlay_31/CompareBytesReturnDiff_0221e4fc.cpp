#include <globaldefs.h>

#pragma optimize_for_size off

// USA: func_ov031_0221e4fc  (semantic: CompareBytesReturnDiff_0221e4fc)
extern "C" THUMB int func_ov031_0221e4fc(unsigned char* a, unsigned char* b, int n) {
    int diff = 0;
    goto check;
    for (;;) {
        a++;
        b++;
    check:
        if (n-- <= 0) break;
        diff = *a - *b;
        if (diff != 0) break;
    }
    return diff;
}
