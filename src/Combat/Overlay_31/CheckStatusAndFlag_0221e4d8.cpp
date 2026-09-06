#include <globaldefs.h>

extern "C" int func_ov031_022077c0();
extern "C" int func_ov031_0221e92c();

// USA: func_ov031_0221e4d8  (semantic: CheckStatusAndFlag_0221e4d8)
extern "C" THUMB int func_ov031_0221e4d8(void) {
    if (func_ov031_022077c0() < 0) {
        return -1;
    }
    return -(func_ov031_0221e92c() != 0);
}
