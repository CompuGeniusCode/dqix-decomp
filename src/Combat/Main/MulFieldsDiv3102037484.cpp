#include <globaldefs.h>

struct S02037484 {
    unsigned char pad[0x40];
    unsigned char lo40 : 3;
    unsigned char a : 5;
    unsigned char b : 5;
    unsigned char hi41 : 3;
};

// USA: func_02037484
ARM int MulFieldsDiv3102037484(struct S02037484* obj) {
    return obj->a * obj->b / 31;
}
