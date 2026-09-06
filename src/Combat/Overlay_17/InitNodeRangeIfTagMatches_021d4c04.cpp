#include <globaldefs.h>
#include "std_library_functions.h"

extern const char data_ov017_021d82d4[];

struct Self021d4c04 {
    int field0;
    char pad4[0xc - 0x4];
    int field0xc;
    int field0x10;
    char pad14[0x18 - 0x14];
    int field0x18;
    int field0x1c;
    int field0x20;
    int field0x24;
    char pad28[0x2c - 0x28];
    int field0x2c;
    char pad30[0x44 - 0x30];
    void* field0x44;
    void* field0x48;
};

// USA: func_ov017_021d4c04  (semantic: InitNodeRangeIfTagMatches_021d4c04)
extern "C" ARM void func_ov017_021d4c04(struct Self021d4c04* self, void* node, int arg2, int arg3, int arg5, int arg6) {
    self->field0x10 = arg2;
    self->field0xc = arg3;
    self->field0x24 = arg5;
    self->field0x20 = arg6;
    self->field0x18 = self->field0x10 + (arg3 << 3);
    self->field0x2c = arg6 * 0xc + self->field0x24;
    self->field0x44 = node;
    self->field0x48 = (char*)node + *(int*)((char*)node + 8);
    if (strncmp((char*)self->field0x44, data_ov017_021d82d4, 3) != 0) return;
    self->field0 = 2;
    self->field0x1c = self->field0x10;
    self->field0x10 = self->field0x10 + *(int*)((char*)self->field0x44 + 0x18) * 8;
    self->field0xc = self->field0xc - *(int*)((char*)self->field0x44 + 0x18);
    memset((void*)self->field0x1c, 0, *(int*)((char*)self->field0x44 + 0x18) * 8);
}
