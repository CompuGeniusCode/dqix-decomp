#include <globaldefs.h>

struct FlagInner_021dce1c {
    char unk[0x14];
    int flags;
};

struct FlagObj_021dce1c {
    char unk[0x138];
    struct FlagInner_021dce1c* inner;
};

// USA: func_ov026_021dce1c
ARM int IsFlagBit8Set_021dce1c(struct FlagObj_021dce1c* obj) {
    return (obj->inner->flags & 0x8) != 0;
}
