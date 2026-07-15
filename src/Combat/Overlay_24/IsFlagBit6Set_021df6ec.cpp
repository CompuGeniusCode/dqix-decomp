#include <globaldefs.h>

struct FlagInner_021df6ec {
    char unk[0x14];
    int flags;
};

struct FlagObj_021df6ec {
    char unk[0x138];
    struct FlagInner_021df6ec* inner;
};

// USA: func_ov024_021df6ec
ARM int IsFlagBit6Set_021df6ec(struct FlagObj_021df6ec* obj) {
    return (obj->inner->flags & 0x40) != 0;
}
