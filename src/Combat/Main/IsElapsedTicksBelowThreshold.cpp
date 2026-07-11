#include <globaldefs.h>

extern "C" unsigned long long func_020c8d5c(void);
extern "C" unsigned long long func_0200cedc(unsigned long long dividend, unsigned int divisor, unsigned int flag);

struct Struct02153628 {
    unsigned int field0;
};
extern struct Struct02153628 data_02153628;

// USA: func_020e11e4
ARM int IsElapsedTicksBelowThreshold(void) {
    unsigned long long now = func_020c8d5c();
    unsigned long long epoch = *(unsigned long long*)((char*)&data_02153628 + 4);
    unsigned long long diff = now - epoch;
    unsigned long long scaled = diff << 6;
    unsigned long long quotient = func_0200cedc(scaled, 0x82ea, 0);
    return quotient < data_02153628.field0;
}
