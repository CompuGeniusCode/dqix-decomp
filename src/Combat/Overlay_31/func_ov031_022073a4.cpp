#include <globaldefs.h>

#pragma optimize_for_size off

extern "C" ARM void func_ov031_022073a4(int a, int b, int c, int d, unsigned char* out);

// USA: func_ov031_0221e5a0  (semantic: StoreByteAndForward_0221e5a0)
extern "C" THUMB void func_ov031_0221e5a0(int a, int b, int c, int d, unsigned char* out, int value) {
    *out = (unsigned char)value;
    func_ov031_022073a4(a, b, c, d, out);
}
