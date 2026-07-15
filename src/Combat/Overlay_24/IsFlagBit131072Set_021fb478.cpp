#include <globaldefs.h>

struct S_flag131072_inner {
    char unk[0x14];
    int flags;
};

struct S_flag131072 {
    char unk[0x138];
    struct S_flag131072_inner* inner;
};

// USA: func_ov024_021fb478
ARM int IsFlagBit131072Set_021fb478(struct S_flag131072* obj) {
    return (obj->inner->flags & 0x20000) != 0;
}
