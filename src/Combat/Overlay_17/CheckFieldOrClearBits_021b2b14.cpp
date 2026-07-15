#include <globaldefs.h>

int GetData02104304Field4(void);
int GetField0x124(void* obj);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_021a2fa0(int h);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);

struct Obj021b2b14 {
    unsigned char pad0[8];
    int f8;
    unsigned char pad1[0x38 - 0xc];
    int f38;
};

// USA: func_ov017_021b2b14
ARM int CheckFieldOrClearBits_021b2b14(Obj021b2b14* p) {
    if (GetField0x124((void*)GetData02104304Field4()) > 0) {
        return p->f8;
    }
    int h = func_ov017_0218b5b0();
    func_ov017_021a2fa0(h);
    ClearBitsInField4((unsigned int*)h, 8);
    ClearBitsInField4((unsigned int*)h, 0x10);
    p->f38 &= ~2;
    return 3;
}
