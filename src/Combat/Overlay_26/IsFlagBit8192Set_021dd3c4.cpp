#include <globaldefs.h>

struct FlagInner_021dd3c4 {
    char unk[0x18];
    int flags;
};

struct FlagObj_021dd3c4 {
    char unk[0x138];
    struct FlagInner_021dd3c4* inner;
};

// USA: func_ov026_021dd3c4
ARM int IsFlagBit8192Set_021dd3c4(struct FlagObj_021dd3c4* obj) {
    return (obj->inner->flags & 0x2000) != 0;
}
