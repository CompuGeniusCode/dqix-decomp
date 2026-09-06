#include <globaldefs.h>

struct FieldBlock63d6_115b4 {
    char unk[0x63D6];
    unsigned char field;
};

// USA: func_020115b4
ARM void SetByteField0x63d6(struct FieldBlock63d6_115b4* obj, unsigned char value) {
    obj->field = value;
}
