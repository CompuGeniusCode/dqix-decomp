#include <globaldefs.h>

struct IdxAndField02229748 { unsigned char idx; int field4; };
extern IdxAndField02229748 data_ov031_02290c5c;
extern unsigned char data_ov031_02248dc4[];

extern "C" int func_ov031_02234ff8(int, int, int);

// USA: func_ov031_02229748
ARM int TailCallLookup_02229748(void) {
    unsigned char idx = data_ov031_02290c5c.idx;
    int field4 = data_ov031_02290c5c.field4;
    unsigned char val = data_ov031_02248dc4[idx];
    return func_ov031_02234ff8(field4, val, val);
}
