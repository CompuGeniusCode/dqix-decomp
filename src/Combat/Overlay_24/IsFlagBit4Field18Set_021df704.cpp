#include <globaldefs.h>

struct FlagInner_021df704 {
    char unk[0x18];
    int flags;
};

struct FlagObj_021df704 {
    char unk[0x138];
    struct FlagInner_021df704* inner;
};

// USA: func_ov024_021df704
ARM int IsFlagBit4Field18Set_021df704(struct FlagObj_021df704* obj) {
    return (obj->inner->flags & 0x10) != 0;
}
