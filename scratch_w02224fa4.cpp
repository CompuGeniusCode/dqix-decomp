#include <globaldefs.h>

struct SubObj02224fa4 { unsigned int field0; unsigned short field4; };
struct EntityStruct02224fa4 {
    unsigned char pad0[0x30];
    SubObj02224fa4* arr30[47];
    SubObj02224fa4* arrEc[4];
    void* arrFc[1];
};

extern EntityStruct02224fa4* data_ov031_02250bfc;
extern unsigned char data_ov031_022489ac[];
extern unsigned char data_ov031_022489b0[];
extern "C" void func_ov031_0223bb58(void* obj, int a, int b);

#pragma optimize_for_size off
// USA: func_ov031_02224fa4
extern "C" ARM void func_ov031_02224fa4(int idx, int val) {
    if (idx < 0) return;
    if (idx < 0x2f) {
        SubObj02224fa4* p = data_ov031_02250bfc->arr30[idx];
        unsigned char b = data_ov031_022489ac[val];
        p->field0 &= ~0xc00;
        p->field4 = (unsigned short)((p->field4 & ~0xf000) | (b << 12));
        return;
    }
    int off1 = idx - 0x2f;
    if (off1 < 4) {
        unsigned char b = data_ov031_022489ac[val];
        SubObj02224fa4* p = data_ov031_02250bfc->arrEc[off1];
        p->field0 &= ~0xc00;
        p->field4 = (unsigned short)((p->field4 & ~0xf000) | (b << 12));
        return;
    }
    void* p = data_ov031_02250bfc->arrFc[idx - 0x33];
    (void)*(volatile unsigned char*)&data_ov031_022489b0[val];
    func_ov031_0223bb58(p, -1, 0);
}
