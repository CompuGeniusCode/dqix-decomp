#include <globaldefs.h>
typedef int (*VFn_0218f6a0)(void*);
// USA: func_ov016_0218f6a0  (semantic: CallVTableFnAt20_0218f6a0)
extern "C" ARM int func_ov016_0218f6a0(void* obj) {
    return (*(VFn_0218f6a0*)(*(char**)obj + 0x14))(obj);
}
