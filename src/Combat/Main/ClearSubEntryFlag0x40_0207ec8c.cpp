#include <globaldefs.h>

void SetOrClearEntryFlags(unsigned char*, int, int);

struct Obj0207ec8c {
    char unk[0x54];
    void* field_54;
};

// USA: func_0207ec8c
ARM void ClearSubEntryFlag0x40_0207ec8c(struct Obj0207ec8c* obj) {
    if (obj->field_54 == NULL) return;
    SetOrClearEntryFlags((unsigned char*)obj->field_54, 0, 0x40);
}
