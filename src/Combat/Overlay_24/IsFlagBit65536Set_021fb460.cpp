#include <globaldefs.h>

struct S_flag10000_inner {
    char unk[0x14];
    int flags;
};

struct S_flag10000 {
    char unk[0x138];
    struct S_flag10000_inner* inner;
};

// USA: func_ov024_021fb460
ARM int IsFlagBit65536Set_021fb460(struct S_flag10000* obj) {
    return (obj->inner->flags & 0x10000) != 0;
}
