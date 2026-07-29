#include <globaldefs.h>

struct Args4_02008f3c { int a; unsigned int b; int c; int d; };

// USA: func_02008f3c  (semantic: ClampArg1_02008f3c)
extern "C" ARM int func_02008f3c(struct Args4_02008f3c args) {
    char* base = (char*)&args;
    unsigned int* p = (unsigned int*)(base + 4);
    *p &= 0x7fffffff;
    return args.a;
}
