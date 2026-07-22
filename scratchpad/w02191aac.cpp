#include <globaldefs.h>

extern "C" void* func_ov017_0219219c(char* base, int idx);

// USA: func_ov017_02191aac
ARM void SetOrClearMaskBit_02191aac(char* base, int mode, int idx, unsigned char mask) {
    if (!func_ov017_0219219c(base, idx)) return;
    {
        unsigned char* p = (unsigned char*)func_ov017_0219219c(base, idx);
        if (p) *p |= 1;
    }
    if (mode == 1) {
        unsigned char* p = (unsigned char*)func_ov017_0219219c(base, idx);
        if (p) *p |= mask;
        return;
    }
    if (mode != 0) return;
    {
        unsigned char* p = (unsigned char*)func_ov017_0219219c(base, idx);
        if (p) *p &= ~mask;
    }
}
