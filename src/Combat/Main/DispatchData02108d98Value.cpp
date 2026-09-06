#include <globaldefs.h>

struct Data02108d98 {
    unsigned short field0;   // 0x0
    unsigned short field2;   // 0x2
    int field4;              // 0x4
    int field8;              // 0x8
    int fieldC;              // 0xc
};
extern struct Data02108d98 data_02108d98;

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
extern "C" void func_02071c64(int a, int b, int c);

// USA: func_02071820
ARM int DispatchData02108d98Value(struct Variant02030b0c* variant) {
    if (data_02108d98.field4 != 0 && data_02108d98.field0 != 0) {
        func_02071c64(data_02108d98.fieldC, data_02108d98.field8, data_02108d98.field0);
    } else {
        func_02071c64(data_02108d98.fieldC, data_02108d98.field8,
                      (unsigned short)_ZNK6Script9Parameter5ToIntEv(variant));
    }
    return 1;
}
