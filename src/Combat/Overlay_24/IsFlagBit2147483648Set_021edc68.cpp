#include <globaldefs.h>

struct S_flag80000000_inner {
    char unk[0x14];
    int flags;
};

struct S_flag80000000 {
    char unk[0x138];
    struct S_flag80000000_inner* inner;
};

// USA: func_ov024_021edc68
ARM int IsFlagBit2147483648Set_021edc68(struct S_flag80000000* obj) {
    return (obj->inner->flags & 0x80000000) != 0;
}
