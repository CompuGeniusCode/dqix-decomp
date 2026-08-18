#include <globaldefs.h>
#include "std_library_functions.h"

extern int data_ov031_0224f670;

typedef void* (*AllocFn0224f670)(int);

// USA: func_ov031_0222288c  (semantic: AllocZeroed_0222288c)
extern "C" THUMB void* func_ov031_0222288c(int a, int b) {
    int size = a * b;
    AllocFn0224f670 fn = *(AllocFn0224f670*)((char*)&data_ov031_0224f670 + 4);
    void* p = fn(size);
    if (p) {
        memset(p, 0, size);
    }
    return p;
}
