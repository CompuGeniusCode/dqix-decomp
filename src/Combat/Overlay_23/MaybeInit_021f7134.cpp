#include <globaldefs.h>

extern "C" void func_02047554(void*, int, int);

// USA: func_ov023_021f7134
ARM void MaybeInit_021f7134(char* obj) {
    if (*(unsigned char*)(obj + 0xc) & 8) return;
    func_02047554(obj + 0x20, 0, 1);
}
