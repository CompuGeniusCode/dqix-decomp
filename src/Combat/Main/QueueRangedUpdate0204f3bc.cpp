#include <globaldefs.h>

extern "C" void func_0204cc68(void* obj, int a, int b, int idx, short c, short d);

struct Obj0204f3bc {
    char pad[0xa8];
    short fieldA8;
    short fieldAA;
};

// USA: func_0204f3bc  (semantic: QueueRangedUpdate0204f3bc)
extern "C" ARM void func_0204f3bc(struct Obj0204f3bc* obj, int idx) {
    if (idx < 0) return;
    short aa = obj->fieldAA;
    short a8 = obj->fieldA8;
    short a8x8 = a8 << 3;
    short aax8 = aa << 3;
    if (idx >= aax8) return;
    short c = (short)(a8x8 - 1);
    short d = (short)(idx + 1);
    func_0204cc68(obj, 0xf, 1, idx, c, d);
}
