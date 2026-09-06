#include <globaldefs.h>

extern "C" void func_02037d10(void* obj);

struct Obj02048104 {
    unsigned short flags;   // 0x0
};

// USA: func_02048104
ARM void SetFlag0x20002048104(struct Obj02048104* obj) {
    func_02037d10(obj);
    obj->flags |= 0x200;
}
