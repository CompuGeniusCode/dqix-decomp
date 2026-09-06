#include <globaldefs.h>

struct EntityStruct022143f4 { unsigned char pad[0xb]; unsigned char fieldb; };

// USA: func_ov031_022143f4
ARM int GetFieldbSelect_022143f4(struct EntityStruct022143f4* e) {
    return e->fieldb == 0 ? (int)0xffff3c4d : (int)0xffff3865;
}
