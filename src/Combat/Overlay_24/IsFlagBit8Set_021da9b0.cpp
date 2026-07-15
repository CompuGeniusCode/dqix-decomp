#include <globaldefs.h>

struct FlagInner_021da9b0 {
    char unk[0x14];
    int flags;
};

struct FlagObj_021da9b0 {
    char unk[0x138];
    struct FlagInner_021da9b0* inner;
};

// USA: func_ov024_021da9b0
ARM int IsFlagBit8Set_021da9b0(struct FlagObj_021da9b0* obj) {
    return (obj->inner->flags & 0x8) != 0;
}
