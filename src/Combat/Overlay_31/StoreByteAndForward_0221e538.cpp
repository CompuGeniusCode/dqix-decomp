#include <globaldefs.h>
#pragma optimize_for_size off

extern "C" int func_ov031_022072d0(int a0, int a1, int a2, int a3, void* dst);

// USA: func_ov031_0221e538  (semantic: StoreByteAndForward_0221e538)
extern "C" THUMB int func_ov031_0221e538(int a0, int a1, int a2, int a3, unsigned char* dst, int* src) {
    *dst = (unsigned char)*src;
    return func_ov031_022072d0(a0, a1, a2, a3, dst);
}
