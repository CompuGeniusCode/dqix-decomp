#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/ExtendedNitroVM.h"

struct BattleWidth020305c8;
int ClearPendingAndAccumulate(struct BattleWidth020305c8* obj, unsigned short* ptr);
extern "C" void func_020d970c(void);
extern "C" void func_020d974c(void);

struct SlotEntry02030110 {
    char pad0[0x32];
    signed char mode : 4;
    unsigned char modeHi : 4;
    char pad33;
    SafeAllocator* alloc;
    void* data;
    int f3c;
    unsigned short u0;
    unsigned short u1;
};

struct BigContext02030110 {
    char pad0[0xc4];
    char extNitro[0x4c];
    char pad110[0x124 - 0x110];
    int slotCount;
    char pad128[0x78c - 0x128];
    int f78c;
};

// USA: func_02030110
extern "C" ARM void func_02030110(struct BigContext02030110* obj) {
    struct SlotEntry02030110* p;
    int zero;
    int i;

    if (obj->slotCount == 0) {
        return;
    }
    func_020d970c();
    p = (struct SlotEntry02030110*)((char*)obj + 0x128);
    zero = 0;
    for (i = zero; i < obj->slotCount; i++, p++) {
        switch (p->mode) {
        case 2:
            ClearPendingAndAccumulate((struct BattleWidth020305c8*)obj, &p->u0);
            if (p->alloc != 0) {
                p->alloc->Free(p->data);
            }
            p->data = (void*)zero;
            p->f3c = zero;
            break;
        case 5:
            goto skipClear;
        }
        p->mode = 0;
    skipClear:;
    }
    ((ExtendedNitroVM*)obj->extNitro)->Abort();
    *(volatile int*)&obj->f78c &= ~1;
    *(volatile int*)&obj->f78c |= 4;
    func_020d974c();
}
