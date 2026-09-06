#include <globaldefs.h>

struct FieldBlock63d6_11590 {
    char unk[0x63D6];
    unsigned char field;
};

// USA: func_02011590
ARM int IsByte0x63d6Set(struct FieldBlock63d6_11590* obj) {
    return obj->field != 0;
}
