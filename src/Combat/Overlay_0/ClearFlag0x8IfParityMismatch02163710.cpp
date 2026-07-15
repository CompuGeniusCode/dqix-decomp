#include <globaldefs.h>

extern "C" void func_02019678(void* ptr, int flag);

struct Flags0951_02163710 {
    unsigned char pad0 : 3;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char pad1 : 3;
};

// USA: func_ov000_02163710
ARM void ClearFlagIfParityMismatch02163710_02163710(void* obj, int flag) {
    struct Flags0951_02163710* f = (struct Flags0951_02163710*)((char*)obj + 0x5000 + 0x951);
    if (!f->bit3) {
        return;
    }
    if (flag == 0) {
        int val = *(int*)((char*)obj + 0x5000 + 0x5d8);
        if ((int)f->bit4 == val % 2) {
            return;
        }
    }
    func_02019678((char*)obj + 0x2c8 + 0xc00, 1);
    volatile unsigned char* p = (unsigned char*)obj + 0x5000 + 0x951;
    *p = *p & ~8;
}
