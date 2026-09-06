#include <globaldefs.h>

struct S_flag100000_inner {
    char unk[0x14];
    int flags;
};

struct S_flag100000 {
    char unk[0x138];
    struct S_flag100000_inner* inner;
};

// USA: func_ov024_021edc20
ARM int IsFlagBit1048576Set_021edc20(struct S_flag100000* obj) {
    return (obj->inner->flags & 0x100000) != 0;
}
