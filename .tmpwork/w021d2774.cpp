#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void _Z19SetFlagBit_0218d4b8Phi(unsigned char* base, int bit);
extern "C" void _Z21ClearFlagBit_0218d4d0Pvi(void* obj, int bit);

struct Ctx021d2774 { char pad[4]; unsigned char byte4; unsigned char byte5; };

// USA: func_ov017_021d2774
ARM void SetOrClearFlagBit_021d2774(void* unused, struct Ctx021d2774* self) {
    void* base = (void*)func_ov017_0218b5b0();
    if (self->byte5 != 0) {
        _Z19SetFlagBit_0218d4b8Phi((unsigned char*)base, self->byte4);
    } else {
        _Z21ClearFlagBit_0218d4d0Pvi(base, self->byte4);
    }
}
