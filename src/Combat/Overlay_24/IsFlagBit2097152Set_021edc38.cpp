#include <globaldefs.h>

struct S_flag200000_inner {
    char unk[0x14];
    int flags;
};

struct S_flag200000 {
    char unk[0x138];
    struct S_flag200000_inner* inner;
};

// USA: func_ov024_021edc38
ARM int IsFlagBit2097152Set_021edc38(struct S_flag200000* obj) {
    return (obj->inner->flags & 0x200000) != 0;
}
