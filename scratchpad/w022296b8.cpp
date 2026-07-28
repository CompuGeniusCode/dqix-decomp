#include <globaldefs.h>

int HwDivideRemainder(int numer, int denom);
extern "C" int func_ov031_02236878(int index);
extern "C" int func_ov031_022237dc(int, int, int, int);

struct IdxStruct022296b8 { unsigned char idx; };
extern IdxStruct022296b8 data_ov031_02290c5c;

extern unsigned short data_ov031_02248e12[];
extern unsigned short data_ov031_02248e16[];
extern unsigned short data_ov031_02248e14[];
extern unsigned short data_ov031_02248e18[];

// USA: func_ov031_022296b8
extern "C" ARM void func_ov031_022296b8(int input) {
    if (input == 1) {
        data_ov031_02290c5c.idx = (unsigned char)HwDivideRemainder(data_ov031_02290c5c.idx + 2, 3);
    } else {
        data_ov031_02290c5c.idx = (unsigned char)HwDivideRemainder(data_ov031_02290c5c.idx + 1, 3);
    }
    func_ov031_02236878(8);
    int idx = data_ov031_02290c5c.idx;
    func_ov031_022237dc(data_ov031_02248e12[idx * 4], data_ov031_02248e16[idx * 4],
        data_ov031_02248e14[idx * 4], data_ov031_02248e18[idx * 4]);
}
