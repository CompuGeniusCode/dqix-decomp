#include <globaldefs.h>

extern "C" void _ZN8Object3D4DrawEb(void* p, int flag);
int CallWithOffset1e0_02173ef4(void* obj);

// USA: func_ov003_0216d5f0  (semantic: ProcessEntryAndOffset_0216d5f0)
extern "C" ARM void func_ov003_0216d5f0(char* obj) {
    if (*(unsigned char*)(obj + 0x1000 + 0x3e8) != 0) {
        _ZN8Object3D4DrawEb(obj + 0x133c, 1);
    }
    if (*(short*)(obj + 0x4) == 5 && *(short*)(obj + 0x6) == 6) {
        CallWithOffset1e0_02173ef4(obj + 0xf1c);
    }
}
