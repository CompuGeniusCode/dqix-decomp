#include <globaldefs.h>

struct FieldObj_021fc498;
int GetFieldNibble_021fc498(struct FieldObj_021fc498* obj);

extern "C" void func_ov024_021fb91c(void* obj);

struct Struct_021fcb60 {
    char unk0[0x6];
    unsigned char type;
    char pad7;
    struct FieldObj_021fc498* field8;
    int field0xc;
    char unk10[0x124 - 0x10];
    float f124;
};

// USA: func_ov024_021fcb60
ARM void AdjustFieldScale_021fcb60(struct Struct_021fcb60* obj) {
    float saved = obj->f124;
    obj->f124 = 0.6f;
    if (obj->type == 3) {
        obj->f124 = 0.65f;
    }
    if (!(GetFieldNibble_021fc498(obj->field8) > 2 && obj->field0xc > 2)) {
        obj->f124 += 0.2f;
    }
    func_ov024_021fb91c(obj);
    obj->f124 = saved;
}
