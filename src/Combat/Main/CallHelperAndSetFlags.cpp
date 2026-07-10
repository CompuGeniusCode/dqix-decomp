#include <globaldefs.h>

struct HelperArgs020b9658 {
    int field0;
    int pad4;
    void* field8;
};

struct FlagObject020b9658 {
    unsigned int field0;
    char pad4[0xC];
    unsigned int field10;
};

extern "C" void func_020b9484(void* target, unsigned short a1, int a2, void* a3);

// USA: func_020b9658
ARM void CallHelperAndSetFlags(struct FlagObject020b9658* obj, struct HelperArgs020b9658* args, int a2) {
    void* target = args->field8;
    int value = args->field0;
    func_020b9484(target, (unsigned short)a2, value >> 12, obj);
    obj->field10 = (obj->field10 & ~0xC0000000) | 0x40000000;
    obj->field0 |= 8;
}
