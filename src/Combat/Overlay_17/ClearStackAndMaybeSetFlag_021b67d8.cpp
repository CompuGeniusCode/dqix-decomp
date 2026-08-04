#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void PopStack0AndTrigger(int flag);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern "C" void func_020a0c0c(void);
extern "C" void* func_ov017_0218b5b0(void);
struct ListHead02046b60;
int ListContainsId(struct ListHead02046b60* list, int id);
extern "C" void* func_0202ae18(void);

extern int data_02114e20;

struct Obj021b67d8 {
    unsigned char pad0[0x8];
    SafeAllocator allocator;
    unsigned char pad24[0x24 - 0x8 - sizeof(SafeAllocator)];
    void* field24;
};

struct Ctx021b67d8 {
    unsigned char pad0[0x6fc];
    struct ListHead02046b60* list6fc;
    unsigned char pad734[0x734 - 0x6fc - 4];
    unsigned char* field734;
};

// USA: func_ov017_021b67d8  (semantic: ClearStackAndMaybeSetFlag_021b67d8)
extern "C" ARM void func_ov017_021b67d8(struct Obj021b67d8* self) {
    if (self->field24 != NULL) {
        self->field24 = NULL;
        PopStack0AndTrigger(1);
    }

    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
    }

    func_020a0c0c();

    int flag = 1;
    struct Ctx021b67d8* ctx = (struct Ctx021b67d8*)((char*)func_ov017_0218b5b0() + 0x3000);
    struct ListHead02046b60* list = ctx->list6fc;
    unsigned char* field = ctx->field734;

    if (ListContainsId(list, 0x18) != 0) {
        flag = 0;
    }
    if (ListContainsId(list, 4) != 0) {
        if (field[0xcc] == 1) {
            flag = 0;
        }
    }
    if (flag == 0) {
        return;
    }

    char* q = (char*)func_0202ae18();
    q[0x1000 + 0x11] = 1;
}
