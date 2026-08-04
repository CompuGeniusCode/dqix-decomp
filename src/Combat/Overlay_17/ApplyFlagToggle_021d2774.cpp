#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
void SetFlagBit_0218d4b8(unsigned char* base, int bit);
void ClearFlagBit_0218d4d0(void* obj, int bit);

struct Obj021d2774 { unsigned char pad0[4]; unsigned char flagIdx; unsigned char enable; };

// USA: func_ov017_021d2774  (semantic: ApplyFlagToggle_021d2774)
extern "C" ARM void func_ov017_021d2774(void* a, Obj021d2774* p) {
    void* obj = func_ov017_0218b5b0();
    if (p->enable != 0)
        SetFlagBit_0218d4b8((unsigned char*)obj, p->flagIdx);
    else
        ClearFlagBit_0218d4d0(obj, p->flagIdx);
}
