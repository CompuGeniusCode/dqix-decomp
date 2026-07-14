#include <globaldefs.h>

int ResetVramBanks0211122c();
int func_020c4a70();
int ResetVramBanks02111226();
int ResetVramBanks02111228();
int func_020c4ac0();
int ProcessFlagWord02111238();

struct FieldSet02097bc4 {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    char pad18[6];
    unsigned char field1e;
};

// USA: func_02097bc4
ARM void SetFieldGroupFromFlags02097bc4(struct FieldSet02097bc4* obj, int flags) {
    obj->field1e = (unsigned char)flags;
    if (flags & 1) {
        obj->field0 = ResetVramBanks0211122c();
        obj->field4 = func_020c4a70();
        obj->field8 = ResetVramBanks02111226();
        obj->fieldC = ResetVramBanks02111228();
    }
    if (flags & 2) {
        obj->field10 = func_020c4ac0();
        obj->field14 = ProcessFlagWord02111238();
    }
}
