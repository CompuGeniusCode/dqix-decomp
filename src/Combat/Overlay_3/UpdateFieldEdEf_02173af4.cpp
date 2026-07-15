#include <globaldefs.h>

struct Obj02173af4 {
    char pad0[0xed];
    unsigned char fed;
    unsigned char pad1;
    unsigned char fef;
};

extern "C" void* func_ov017_0218b5b0(struct Obj02173af4*);
extern "C" void func_0203b19c(void*, int, int);
int CheckField0x20Positive(int* obj);

// USA: func_ov003_02173af4
ARM void UpdateFieldEdEf_02173af4(struct Obj02173af4* p) {
    void* x = func_ov017_0218b5b0(p);
    if (p->fef == 0) {
        func_0203b19c(x, -16, 0x18);
        p->fef = 1;
        return;
    }
    if (p->fef != 1) return;
    if (!CheckField0x20Positive((int*)x)) {
        p->fed = 6;
        p->fef = 0;
    }
}
