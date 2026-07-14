#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "System/Cache.h"

extern int GetWord0x0(int* obj);
extern int TransferMainObjPalette(int arg0, int arg1, unsigned int arg2);
extern int TransferSubObjPalette(int arg0, int arg1, unsigned int arg2);

struct Inner020e1674 {
    char pad[0x3e];
    unsigned char flag;
};
struct Obj020e1674 {
    char pad[4];
    struct Inner020e1674* ptr;
};
extern void TransferObjPaletteEntry020e1674(struct Obj020e1674* obj, int idx, int sel);

// USA: func_020e16f4
ARM void TransferBattleObjPaletteEntries020e16f4(struct Obj020e1674* self) {
    int field2c;

    if (self->ptr == NULL) return;
    field2c = *(int*)(GetWord0x0((int*)GetBattleStruct()) + 0x2c);
    if (field2c == 0) return;
    CleanInvalidateCacheRange((void*)(field2c + 0xc), 0x20);
    if (self->ptr->flag == 0) {
        TransferMainObjPalette(field2c + 0xc, 0x1c0, 0x20);
    } else {
        TransferSubObjPalette(field2c + 0xc, 0x1c0, 0x20);
    }
    CleanCacheRange((void*)(field2c + 0xc), 0x20);
    TransferObjPaletteEntry020e1674(self, 9, 0);
    TransferObjPaletteEntry020e1674(self, 0xb, 0);
}
