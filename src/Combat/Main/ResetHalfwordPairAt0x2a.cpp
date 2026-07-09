#include <globaldefs.h>

struct ResetHalfwordPair0208977c {
    unsigned char pad[0x2a];
    short field2a;
    short field2c;
};

// USA: func_0208977c
ARM void ResetHalfwordPairAt0x2a(struct ResetHalfwordPair0208977c* p) {
    p->field2a = -1;
    p->field2c = -1;
}
