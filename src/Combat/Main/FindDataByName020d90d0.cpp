#include <globaldefs.h>

extern "C" int func_01ff860c(const char*);
extern "C" int func_020d9100(void**, unsigned int*, void*, int);

// USA: func_020d90d0
ARM int FindDataByName020d90d0(void** outPtr, unsigned int* outVal, void* table, const char* name) {
    return func_020d9100(outPtr, outVal, table, func_01ff860c(name));
}
