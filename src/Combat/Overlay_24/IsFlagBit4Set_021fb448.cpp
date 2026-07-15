#include <globaldefs.h>

struct S_flag4b_inner {
    char unk[0x18];
    int flags;
};

struct S_flag4b {
    char unk[0x138];
    struct S_flag4b_inner* inner;
};

// USA: func_ov024_021fb448
ARM int IsFlagBit4Set_021fb448(struct S_flag4b* obj) {
    return (obj->inner->flags & 0x4) != 0;
}
