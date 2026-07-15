#include <globaldefs.h>

struct FlagInner_021da9c8 {
    char unk[0x14];
    int flags;
};

struct FlagObj_021da9c8 {
    char unk[0x138];
    struct FlagInner_021da9c8* inner;
};

// USA: func_ov024_021da9c8
ARM int IsFlagBit19Set_021da9c8(struct FlagObj_021da9c8* obj) {
    return (obj->inner->flags & 0x80000) != 0;
}
