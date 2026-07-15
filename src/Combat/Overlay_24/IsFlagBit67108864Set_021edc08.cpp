#include <globaldefs.h>

struct S_flag4000000_inner {
    char unk[0x14];
    int flags;
};

struct S_flag4000000 {
    char unk[0x138];
    struct S_flag4000000_inner* inner;
};

// USA: func_ov024_021edc08
ARM int IsFlagBit67108864Set_021edc08(struct S_flag4000000* obj) {
    return (obj->inner->flags & 0x4000000) != 0;
}
