#include <globaldefs.h>

struct ShortPair02012518 {
    unsigned short f0;
    unsigned short f2;
};

// USA: func_02012518
ARM void ClearTwoHalfwords(struct ShortPair02012518* p) {
    p->f2 = 0;
    p->f0 = 0;
}
