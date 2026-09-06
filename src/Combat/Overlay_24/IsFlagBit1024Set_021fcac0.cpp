#include <globaldefs.h>

struct S_flag1024_inner {
    char unk[0x18];
    int flags;
};

struct S_flag1024 {
    char unk[0x138];
    struct S_flag1024_inner* inner;
};

// USA: func_ov024_021fcac0
ARM int IsFlagBit1024Set_021fcac0(struct S_flag1024* obj) {
    return (obj->inner->flags & 0x400) != 0;
}
