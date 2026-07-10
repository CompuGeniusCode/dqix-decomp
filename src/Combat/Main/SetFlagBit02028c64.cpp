#include <globaldefs.h>

extern "C" void func_0209953c(int arg);

struct Obj02028c64 {
    char pad[4];
    unsigned short flags;   // 0x4
};

// USA: func_02028c64
ARM void SetFlagBit02028c64(struct Obj02028c64* obj, int index) {
    if (index < 0x10) {
        obj->flags |= 1 << index;
        return;
    }
    func_0209953c(5);
}
