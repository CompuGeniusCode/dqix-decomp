#include <globaldefs.h>

extern "C" void func_020ca390(int, void*, unsigned int);
ARM int TailCallForward_0223e2e0(int arg0, void* arg1);
ARM unsigned int GetBg0CharBaseAddr(void);
extern "C" ARM unsigned int func_ov031_0223cf70(void** a);

extern void* data_ov031_02290d38;

// USA: func_ov031_0223c760
extern "C" ARM void func_ov031_0223c760(void* a0) {
    TailCallForward_0223e2e0(1, *(void**)((char*)a0 + 0x2c));
    if (a0 == (char*)data_ov031_02290d38 + 0x610) {
        func_020ca390(0, (void*)GetBg0CharBaseAddr(), 0x6000);
    } else {
        func_020ca390(0, (void*)GetBg0CharBaseAddr(), 0x3000);
    }
    func_ov031_0223cf70((void**)((char*)a0 + 0x28));
}
