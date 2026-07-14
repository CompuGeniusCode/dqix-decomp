#include <globaldefs.h>

void ResetCommandQueue(void);
int SubmitBlock0x40IfNotBusy(int arg);
int SubmitBlock0x80IfNotBusy(int arg);
extern "C" void func_020c2208(void* buf, void* r6);

// USA: func_020b6bb0
ARM void SubmitPendingCommandBlocks(void* r6, void* r5) {
    unsigned char buf[0x40];
    ResetCommandQueue();
    *(unsigned int*)0x4000440 = 0;
    *(unsigned int*)0x4000444 = 0;
    *(unsigned int*)0x4000454 = 0;
    if (r6 != NULL) {
        while (SubmitBlock0x40IfNotBusy((int)buf) != 0) {}
        func_020c2208(buf, r6);
    }
    if (r5 != NULL) {
        while (SubmitBlock0x80IfNotBusy((int)r5) != 0) {}
    }
    *(unsigned int*)0x4000448 = 1;
    *(unsigned int*)0x4000440 = 2;
}
