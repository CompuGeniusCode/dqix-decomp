#include <globaldefs.h>

extern "C" void func_02035a2c(void* p, int flag);

// USA: func_0204715c
ARM void FreeObjectSlot0204715c(char* obj) {
    void* p = *(void**)(obj + 0xe8);
    if (p != NULL) {
        func_02035a2c(p, 1);
        return;
    }
    if (*(unsigned char*)(obj + 0x1d) != 0) {
        func_02035a2c(obj + 0x3c, 1);
    }
}
