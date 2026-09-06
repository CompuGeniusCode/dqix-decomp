#include <globaldefs.h>
#include "std_library_functions.h"

typedef void (*Fn0204a984)(void*, int, int);

// USA: func_0204a984
ARM void InvokeWithCopiedArg0204a984(int* a0, Fn0204a984 fn, char* ctx) {
    int tmp;
    if (ctx == NULL) return;
    memcpy(&tmp, ctx + 0xc, 4);
    fn((void*)(ctx + 0x10), *a0, tmp);
}
