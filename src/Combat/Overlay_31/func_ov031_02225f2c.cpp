#include <globaldefs.h>

struct Point16_02225f2c { unsigned short x, y; };
struct RangeParam_02225f2c { unsigned short f0, f1, f2, f3; };

extern "C" int func_ov031_0223cb34(Point16_02225f2c* a, Point16_02225f2c* b, RangeParam_02225f2c* out);
extern "C" int func_ov031_0223d49c(RangeParam_02225f2c* p);
extern "C" void func_ov031_02236878(int v);

extern RangeParam_02225f2c data_ov031_022493b8;

extern Point16_02225f2c data_ov031_02248cda[10];
extern Point16_02225f2c data_ov031_02248c88;
extern Point16_02225f2c data_ov031_02248cb0[2];
extern Point16_02225f2c data_ov031_02248c90;
extern Point16_02225f2c data_ov031_02248cb8[2];
extern Point16_02225f2c data_ov031_02248c94;

struct Entity02225f2c {
    unsigned char pad[0x61];
    signed char field61;
    unsigned char pad2[4];
    unsigned char field66;
    unsigned char field67;
    unsigned char field68;
};
extern Entity02225f2c* data_ov031_02250c00;

#pragma optimize_for_size off
// USA: func_ov031_02225f2c  (semantic: PickDirectionSlot_02225f2c)
extern "C" ARM void func_ov031_02225f2c(void) {
    RangeParam_02225f2c p;
    if (!func_ov031_0223d49c(&data_ov031_022493b8)) return;
    data_ov031_02250c00->field61 = -1;
    Point16_02225f2c* t1 = data_ov031_02248cda;
    int i = 0;
    do {
        func_ov031_0223cb34(t1, &data_ov031_02248c88, &p);
        if (func_ov031_0223d49c(&p)) {
            if (data_ov031_02250c00->field67 == 0) {
                func_ov031_02236878(9);
                return;
            }
            func_ov031_02236878(0);
            data_ov031_02250c00->field61 = (signed char)i;
            return;
        }
        i++;
        t1++;
    } while (i < 10);
    Point16_02225f2c* t2 = data_ov031_02248cb0;
    i = 0;
    do {
        func_ov031_0223cb34(t2, &data_ov031_02248c90, &p);
        if (func_ov031_0223d49c(&p)) {
            if (i == 0) {
                if (data_ov031_02250c00->field66 == 0) goto call9_l2;
            }
            if (i != 1) goto call0_l2;
            if (data_ov031_02250c00->field68 != 0) goto call0_l2;
        call9_l2:
            func_ov031_02236878(9);
            return;
        call0_l2:
            func_ov031_02236878(0);
            data_ov031_02250c00->field61 = (signed char)(i + 0xa);
            return;
        }
        i++;
        t2++;
    } while (i < 2);
    Point16_02225f2c* t3 = data_ov031_02248cb8;
    int j = 0;
    do {
        func_ov031_0223cb34(t3, &data_ov031_02248c94, &p);
        if (func_ov031_0223d49c(&p)) {
            func_ov031_02236878(0);
            data_ov031_02250c00->field61 = (signed char)(j + 0xc);
            return;
        }
        j++;
        t3++;
    } while (j < 2);
}
