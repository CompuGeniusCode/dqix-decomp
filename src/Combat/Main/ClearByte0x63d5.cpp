#include <globaldefs.h>

struct FieldBlock63d5_12050 {
    char unk[0x63D5];
    unsigned char field;
};

// USA: func_02012050
ARM void ClearByte0x63d5(struct FieldBlock63d5_12050* obj) {
    obj->field = 0;
}
