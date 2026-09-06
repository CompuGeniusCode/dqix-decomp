#include <globaldefs.h>

unsigned int DisableSpecificInterrupts(unsigned int mask);
void SetInterruptHandler(unsigned int mask, const void* proc);

struct HwCallbackState020ca24c {
    int flag;                  // 0x0
    char pad[0xc];             // 0x4
    void (*callback)(void*);   // 0x10
    void* arg;                 // 0x14
    unsigned int regBits;      // 0x18
    unsigned int altMask;      // 0x1c
};
extern struct HwCallbackState020ca24c data_02111684;

// USA: func_020ca24c
ARM void UpdateHwRegBitsAndFireCallback020ca24c(void) {
    void (*callback)(void*);
    void* arg;

    DisableSpecificInterrupts(0x200000);
    *(volatile unsigned int*)0x4000600 =
        (data_02111684.regBits << 30) | (*(volatile unsigned int*)0x4000600 & ~0xc0000000);
    SetInterruptHandler(0x200000, (const void*)data_02111684.altMask);

    data_02111684.flag = 0;
    callback = data_02111684.callback;
    arg = data_02111684.arg;
    if (callback != NULL) {
        callback(arg);
    }
}
