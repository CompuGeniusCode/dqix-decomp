#include <globaldefs.h>

struct FieldObj_021fc498Inner {
    char unk[0x3b];
    unsigned char lowNibble:4;
    unsigned char highNibble:4;
};

struct FieldObj_021fc498 {
    char unk[0x138];
    struct FieldObj_021fc498Inner* inner;
};

// USA: func_ov024_021fc498
ARM int GetFieldNibble_021fc498(struct FieldObj_021fc498* obj) {
    return obj->inner->highNibble;
}
