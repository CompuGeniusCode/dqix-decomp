#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void PushInputLogB(int id);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov028_021d8b90(void);
extern "C" void func_ov028_021d8b44(void*, void*);

struct Data021658b8_19bc { SafeAllocator* field0; };
extern Data021658b8_19bc data_ov001_021658b8;

struct Ctx19bc { char pad[0x160]; void* field160; unsigned char field164; };

// USA: func_ov001_021619bc
ARM int Func_021619bc(void) {
    PushInputLogB(5);
    char* p = (char*)func_ov017_0218b5b0() + 0x3000;
    Ctx19bc* ctx = *(Ctx19bc**)(p + 0x734);
    void* buf = data_ov001_021658b8.field0->Allocate(0x84);
    if (!buf) return 0;
    ctx->field160 = buf;
    ctx->field164 = 0;
    func_ov028_021d8b90();
    func_ov028_021d8b44(buf, data_ov001_021658b8.field0);
    return 1;
}
