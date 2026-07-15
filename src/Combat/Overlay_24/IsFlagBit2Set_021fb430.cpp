#include <globaldefs.h>

struct S_flag2b_inner {
    char unk[0x18];
    int flags;
};

struct S_flag2b {
    char unk[0x138];
    struct S_flag2b_inner* inner;
};

// USA: func_ov024_021fb430
ARM int IsFlagBit2Set_021fb430(struct S_flag2b* obj) {
    return (obj->inner->flags & 0x2) != 0;
}
