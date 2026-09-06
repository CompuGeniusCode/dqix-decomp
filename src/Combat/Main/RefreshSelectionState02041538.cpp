#include <globaldefs.h>

extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* self, void* a, int b);
extern "C" void _ZN8Object3D21MaybeSetBCFGAnimationEii(void* self, int a, int b);

struct Struct02041538 {
    char pad0[0x14];
    void* field14;                  // 0x14
    char pad18[0x18 - 0x14 - 4];
    signed char field18;            // 0x18
    char pad_ac[0xac - 0x18 - 1];
    unsigned short field_ac;        // 0xac
    char pad_c4[0xc4 - 0xac - 2];
    unsigned char field_c4;         // 0xc4
    char pad_cc[0xcc - 0xc4 - 1];
    void* field_cc;                 // 0xcc
    int field_d0;                   // 0xd0
    unsigned char field_d4_b0 : 1;  // 0xd4 bit 0
};

// USA: func_02041538
ARM void RefreshSelectionState02041538(struct Struct02041538* self) {
    if (self->field_d4_b0) return;
    self->field_ac &= ~1;
    if (self->field_cc != NULL) {
        if (self->field14 == self->field_cc) return;
        _ZN8Object3D24MaybeSetRegularAnimationEPKci(self, self->field_cc, self->field_d0);
    } else {
        if (self->field_c4 == self->field18) return;
        _ZN8Object3D21MaybeSetBCFGAnimationEii(self, self->field_c4, self->field_d0);
    }
}
