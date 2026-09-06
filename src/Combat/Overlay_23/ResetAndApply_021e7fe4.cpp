#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov023_021e868c(void*);

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0*, int, int, int, unsigned char);

// USA: func_ov023_021e7fe4
ARM void ResetAndApply_021e7fe4(void* obj) {
    memset(*(void**)((char*)obj + 0x5d8), 0, 0x960);
    func_ov023_021e868c(obj);
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x78), 0xb, *(int*)((char*)obj + 0x5d8), 1, 0);
}
