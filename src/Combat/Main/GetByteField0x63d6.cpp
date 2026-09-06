#include <globaldefs.h>

struct FieldBlock63d6_115a8 {
    char unk[0x63D6];
    unsigned char field;
};

// USA: func_020115a8
ARM int GetByteField0x63d6(struct FieldBlock63d6_115a8* obj) {
    return obj->field;
}
