#include <globaldefs.h>

extern "C" void func_0205c96c(void* obj, int arg);

// USA: func_02044530
ARM void CallFunc0205c96cIfMode6AndFlag(char* base, int arg) {
    if (*(int*)(base + 0x9a0) != 6) return;
    if (*(unsigned char*)(base + 0x19ba) == 0) return;
    func_0205c96c(base + 0x90, arg);
}
