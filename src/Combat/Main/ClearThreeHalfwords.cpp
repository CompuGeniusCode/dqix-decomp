#include <globaldefs.h>

struct HalfwordTriple0202e98c {
    char pad[0x212];
    unsigned short field212;
    unsigned short field214;
    unsigned short field216;
};

// USA: func_0202e98c
ARM void ClearThreeHalfwords(struct HalfwordTriple0202e98c* p) {
    p->field212 = 0;
    p->field214 = 0;
    p->field216 = 0;
}
