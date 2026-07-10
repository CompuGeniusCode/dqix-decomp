#include <globaldefs.h>

struct S02037484;
struct Obj0207ebc4;
int MulFieldsDiv3102037484(struct S02037484* obj);
void ResetSubAndSetShort0207ebc4(struct Obj0207ebc4* obj, short val);

struct S02037418 {
    char pad0[0x8];
    void* field_8;
    char pad1[0x34];
    unsigned char lo40 : 3;
    unsigned char a : 5;
    char pad2[0x2b];
    unsigned int field_6c;
};

// USA: func_02037418
ARM void SetFieldAAndSync02037418(struct S02037418* obj, int val) {
    unsigned char v;
    obj->a = val;
    if (obj->field_8 == NULL) return;
    if (obj->field_6c & 0x20000000) return;
    v = MulFieldsDiv3102037484((struct S02037484*)obj);
    ResetSubAndSetShort0207ebc4((struct Obj0207ebc4*)obj->field_8, v);
}
