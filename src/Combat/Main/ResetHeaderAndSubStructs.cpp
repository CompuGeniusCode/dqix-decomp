#include <globaldefs.h>

struct Struct02047230;
extern "C" void func_0204719c(struct Struct02047230* obj);

// USA: func_020133cc
ARM void ResetHeaderAndSubStructs(char* base) {
    *(short*)(base + 0x0) = 0;
    *(short*)(base + 0x2) = -1;
    *(short*)(base + 0x4) = 0;
    func_0204719c((struct Struct02047230*)(base + 0x8));
    func_0204719c((struct Struct02047230*)(base + 0x90));
}
