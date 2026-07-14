#include <globaldefs.h>

extern "C" void func_020ca3ec(int value, void* dst, int size);
extern "C" void func_020b4068(void* ctx, void* self);

struct FlaggedEntry020B4204;
void SetBitsForFlaggedEntries(unsigned int* bits, FlaggedEntry020B4204* node);

extern void* data_0210a274;

struct FlagDispatchContext020B426C {
    unsigned int flags;              // 0x00
    unsigned char pad4[4];           // 0x04
    FlaggedEntry020B4204* node0;     // 0x08
    unsigned char padC[4];           // 0x0C
    FlaggedEntry020B4204* node1;     // 0x10
    unsigned char pad14[4];          // 0x14
    FlaggedEntry020B4204* node2;     // 0x18
    unsigned char pad1c[0x20];       // 0x1C
    unsigned int bits0[2];           // 0x3C
    unsigned int bits1[2];           // 0x44
    unsigned int bits2[2];           // 0x4C
};

#pragma optimize_for_size off
// USA: func_020b426c
ARM void UpdateFlagBitsAndDispatch(FlagDispatchContext020B426C* obj) {
    if ((obj->flags & 0x10) == 0x10) {
        func_020ca3ec(0, obj->bits0, sizeof(obj->bits0));
        func_020ca3ec(0, obj->bits1, sizeof(obj->bits1));
        func_020ca3ec(0, obj->bits2, sizeof(obj->bits2));

        if (obj->node0 != NULL)
            SetBitsForFlaggedEntries(obj->bits0, obj->node0);
        if (obj->node1 != NULL)
            SetBitsForFlaggedEntries(obj->bits1, obj->node1);
        if (obj->node2 != NULL)
            SetBitsForFlaggedEntries(obj->bits2, obj->node2);

        obj->flags &= ~0x10;
    }

    if (data_0210a274 != NULL) {
        func_020b4068(data_0210a274, obj);
        return;
    }

    char localBuf[0x188];
    data_0210a274 = localBuf;
    func_020b4068(localBuf, obj);
    data_0210a274 = NULL;
}
