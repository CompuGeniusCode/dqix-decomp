#include <globaldefs.h>

extern "C" int func_020c8074(void*);
extern int data_02112754;

// USA: func_020d21f8
// Kept as extern "C" func_020d21f8: ResolveOffsetOrPointerEntry references this symbol.
extern "C" ARM void func_020d21f8(void) {
    func_020c8074(&data_02112754);
}
