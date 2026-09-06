#include <globaldefs.h>

struct S_020103b4 {
    char unk[0x3dc];
    int field3dc;
};

// USA: func_020103b4
ARM int IsField3dcSet(struct S_020103b4* obj) {
    return obj->field3dc != 0;
}
