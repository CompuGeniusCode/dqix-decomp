#include <globaldefs.h>

void ResetStreamContext02037138(unsigned char*);

struct S020373cc {
    unsigned char pad[0xc];
    int fc;
};

// USA: func_020373cc
ARM void ResetAndClearFieldC020373cc(struct S020373cc* obj) {
    ResetStreamContext02037138((unsigned char*)obj);
    obj->fc = 0;
}
