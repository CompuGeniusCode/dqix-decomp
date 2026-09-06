#include <globaldefs.h>

struct Struct02047230;
extern "C" void func_0204719c(struct Struct02047230* obj);
void MaybeInvoke0204719c(struct Struct02047230* obj);

// USA: func_02012fa4
ARM void ResetFourSubStructs(char* base) {
    signed char i;
    for (i = 0; i < 4; i++) {
        MaybeInvoke0204719c((struct Struct02047230*)(base + i * 0x88));
        func_0204719c((struct Struct02047230*)(base + i * 0x88));
    }
}
