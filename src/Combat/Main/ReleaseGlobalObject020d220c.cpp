#include <globaldefs.h>

extern "C" int func_020c80f8(void*);
extern int data_02112754;

// USA: func_020d220c
// Kept as extern "C" func_020d220c: ResolveOffsetOrPointerEntry references this symbol.
extern "C" ARM void func_020d220c(void) {
    func_020c80f8(&data_02112754);
}
