#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);

// USA: func_020e3368
ARM void StoreInFirstEmptySlot(unsigned char* base, unsigned char val) {
    unsigned char* p;
    int i;
    if (!CheckField0NonZero((int*)func_0202ae18())) return;
    p = base + 0x20;
    for (i = 0; i < 8; i++, p++) {
        if (*p == 0) {
            *p = val;
            return;
        }
    }
}
