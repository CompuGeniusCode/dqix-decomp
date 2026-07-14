#include <globaldefs.h>

struct Inner020e1674 {
    char pad[0x3e];
    unsigned char flag;
};
struct Obj020e1674 {
    char pad[4];
    struct Inner020e1674* ptr;
};
void TransferObjPaletteEntry020e1674(struct Obj020e1674* obj, int idx, int sel);

extern "C" void func_020e1a74(struct Obj020e1674* obj);

struct SelfState020e2834 {
    char pad[0x10];
    struct Obj020e1674* obj;
    signed char flag14;
    char pad2[0x17 - 0x15];
    unsigned char flag17;
};

// USA: func_020e2834
ARM void SetYesNoButtonPalette020e2834(struct SelfState020e2834* self)
{
    *(short*)((char*)self->obj + 0x22) = 0x7fff;
    *(short*)((char*)self->obj + 0x24) = 0xf0a;

    if (self->flag17 != 0) {
        if (self->flag14 == 0) {
            TransferObjPaletteEntry020e1674(self->obj, 9, 1);
            TransferObjPaletteEntry020e1674(self->obj, 0xb, 0);
        } else {
            TransferObjPaletteEntry020e1674(self->obj, 9, 0);
            TransferObjPaletteEntry020e1674(self->obj, 0xb, 1);
        }
    } else {
        TransferObjPaletteEntry020e1674(self->obj, 9, 0);
        TransferObjPaletteEntry020e1674(self->obj, 0xb, 0);
    }

    func_020e1a74(self->obj);
}
