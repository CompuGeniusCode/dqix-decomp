#include <globaldefs.h>

struct S02037484;
int MulFieldsDiv3102037484(struct S02037484* obj);

struct Ctx020359c8 {
    char pad[0x8];
    int f8;
    char pad2[0x6c - 0xc];
    unsigned int f6c;
};

// USA: func_020359c8
ARM int CheckAndToggleFlag0x200000(struct Ctx020359c8* obj) {
    if (obj->f8 == 0) {
        return 0;
    }
    if ((MulFieldsDiv3102037484((struct S02037484*)obj) & 0xff) == 0) {
        return 0;
    }
    unsigned int f6c = obj->f6c;
    if (f6c & 1) {
        return 0;
    }
    if (f6c & 0x100000) {
        if (f6c & 0x200000) {
            f6c &= ~0x200000;
            obj->f6c = f6c;
            return 0;
        }
        f6c |= 0x200000;
        obj->f6c = f6c;
    }
    return 1;
}
