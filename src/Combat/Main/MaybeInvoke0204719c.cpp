#include <globaldefs.h>

struct Struct02047230 {
    unsigned char pad[0x84];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
};

extern "C" void func_0204719c(struct Struct02047230* obj);

// USA: func_02047230
ARM void MaybeInvoke0204719c(struct Struct02047230* obj) {
    if (obj->b0) {
        func_0204719c(obj);
    }
}
