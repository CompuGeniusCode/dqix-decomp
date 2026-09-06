#include <globaldefs.h>

struct FlagInner_021da998 {
    char unk[0x14];
    int flags;
};

struct FlagObj_021da998 {
    char unk[0x138];
    struct FlagInner_021da998* inner;
};

// USA: func_ov024_021da998
ARM int IsFlagBit8388608Set_021da998(struct FlagObj_021da998* obj) {
    return (obj->inner->flags & 0x800000) != 0;
}
