#include <globaldefs.h>
#include "System/DMA.h"

int TransferMainOam(int arg0, int arg1, unsigned int arg2);
int TransferSubOam(int arg0, int arg1, unsigned int arg2);

extern int data_021052b4;
extern int data_021056b4;

struct Obj0203bdb0 {
    char pad[0xc];
    unsigned char flagA;
    unsigned char flagB;
};

// USA: func_0203bdb0
ARM void SyncMainSubOam0203bdb0(struct Obj0203bdb0* obj) {
    if (obj->flagA != 0) {
        TransferMainOam((int)&data_021052b4, 0, 0x400);
        DMAMemsetSynchronous(3, (unsigned int)&data_021052b4, 0xc0, 0x400);
    }
    if (obj->flagB != 0) {
        TransferSubOam((int)&data_021056b4, 0, 0x400);
        DMAMemsetSynchronous(3, (unsigned int)&data_021056b4, 0xc0, 0x400);
    }
    if (obj->flagA != 0 || obj->flagB != 0) {
        *(short*)((char*)obj + 0x520) = 4;
    }
}
