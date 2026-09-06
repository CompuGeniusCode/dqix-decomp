#include <globaldefs.h>

struct FlagInner_021dd260 {
    char unk[0x14];
    int flags;
};

struct FlagObj_021dd260 {
    char unk[0x138];
    struct FlagInner_021dd260* inner;
};

// USA: func_ov024_021dd260
ARM int IsFlagBit24Set_021dd260(struct FlagObj_021dd260* obj) {
    return (obj->inner->flags & 0x1000000) != 0;
}
