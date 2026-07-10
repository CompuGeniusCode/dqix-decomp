#include <globaldefs.h>

extern unsigned int DisableInterrupts();
extern char data_021112e0;
extern "C" void func_020c7764(void);

// USA: func_020c772c
ARM void InvokeAndClearCallback0xb4(int arg) {
    void* p = *(void**)(&data_021112e0 + 0x8);
    void* obj = *(void**)p;
    void (*fn)(int) = *(void(**)(int))((char*)obj + 0xb4);
    if (fn != 0) {
        *(void(**)(int))((char*)obj + 0xb4) = 0;
        fn(arg);
        DisableInterrupts();
    }
    func_020c7764();
}
