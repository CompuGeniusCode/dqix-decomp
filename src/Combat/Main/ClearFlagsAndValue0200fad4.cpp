#include <globaldefs.h>
#include "System/Memory.h"

struct State0200fad4 {
    unsigned char pad[6];
    unsigned char a : 1;
    unsigned char b : 7;
    unsigned char pad7;
    int word8;
};

// USA: func_0200fad4
// Zeroes the first 6 bytes, clears the flag bits at +0x6, and clears the word at +0x8.
ARM void ClearFlagsAndValue0200fad4(struct State0200fad4* s) {
    VectorizedMemset(s, 0, 6);
    s->a = 0;
    s->b = 0;
    s->word8 = 0;
}
