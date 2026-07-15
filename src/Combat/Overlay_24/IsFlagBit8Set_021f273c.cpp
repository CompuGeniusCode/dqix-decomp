#include <globaldefs.h>

struct S_flag8b_inner {
    char unk[0x18];
    int flags;
};

struct S_flag8b {
    char unk[0x138];
    struct S_flag8b_inner* inner;
};

// USA: func_ov024_021f273c
ARM int IsFlagBit8Set_021f273c(struct S_flag8b* obj) {
    return (obj->inner->flags & 0x8) != 0;
}
