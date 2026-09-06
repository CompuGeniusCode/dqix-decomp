#include <globaldefs.h>

struct FlagInner_021de25c {
    char unk[0x14];
    int flags;
};

struct FlagObj_021de25c {
    char unk[0x138];
    struct FlagInner_021de25c* inner;
};

// USA: func_ov024_021de25c
ARM int IsFlagBit5Set_021de25c(struct FlagObj_021de25c* obj) {
    return (obj->inner->flags & 0x20) != 0;
}
