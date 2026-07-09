#include <globaldefs.h>

struct FieldBlock63d6_115c0 {
    char unk[0x63D6];
    unsigned char field;
};

// USA: func_020115c0
ARM void ClearByte0x63d6(struct FieldBlock63d6_115c0* obj) {
    obj->field = 0;
}
