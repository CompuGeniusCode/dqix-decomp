#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* obj);

struct Data02109bf4_02163ab4 {
    unsigned char pad[0xc8];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
};
extern struct Data02109bf4_02163ab4 data_02109bf4;

// USA: func_ov001_02163ab4
ARM int SetBit2From021d60f4Zero_02163ab4(void* obj) {
    int v = func_ov017_021d60f4(obj);
    data_02109bf4.b2 = (v == 0);
    return 1;
}
