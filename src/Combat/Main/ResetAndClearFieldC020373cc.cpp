#include <globaldefs.h>

extern "C" void func_02037138(void*);

struct S020373cc {
    unsigned char pad[0xc];
    int fc;
};

// USA: func_020373cc
ARM void ResetAndClearFieldC020373cc(struct S020373cc* obj) {
    func_02037138(obj);
    obj->fc = 0;
}
