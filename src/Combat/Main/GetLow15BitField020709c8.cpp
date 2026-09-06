#include <globaldefs.h>

struct Struct020709c8 {
    unsigned short field : 15;
};

// USA: func_020709c8
ARM int GetLow15BitField020709c8(struct Struct020709c8 *p) {
    return p->field;
}
