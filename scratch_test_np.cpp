#include <globaldefs.h>

struct Point16_02225f2c { unsigned short x, y; };
struct PointPair16_02225f2c { unsigned short x, y, x2, y2; };

extern "C" ARM void func_ov031_0223cb34(Point16_02225f2c*, Point16_02225f2c*, PointPair16_02225f2c*);
extern "C" ARM int func_ov031_0223d49c(PointPair16_02225f2c*);
extern "C" ARM int func_ov031_02236878(int);

extern PointPair16_02225f2c data_ov031_022493b8;

struct StatusStruct_02225f2c {
    unsigned char pad[0x61];
    unsigned char status;
    unsigned char pad2[4];
    unsigned char f66;
    unsigned char f67;
    unsigned char f68;
};
extern StatusStruct_02225f2c* data_ov031_02250c00;

extern Point16_02225f2c data_ov031_02248cda[10];
extern Point16_02225f2c data_ov031_02248c88;
extern Point16_02225f2c data_ov031_02248cb0[2];
extern Point16_02225f2c data_ov031_02248c90;
extern Point16_02225f2c data_ov031_02248cb8[2];
extern Point16_02225f2c data_ov031_02248c94;

// USA: func_ov031_02225f2c
extern "C" ARM void func_ov031_02225f2c() {
    if (!func_ov031_0223d49c(&data_ov031_022493b8)) return;
    data_ov031_02250c00->status = 0xff;
    {
        Point16_02225f2c* b;
        Point16_02225f2c* t;
        PointPair16_02225f2c buf;
        int i;
        for (i = 0, b = &data_ov031_02248c88, t = data_ov031_02248cda; i < 10; i++, t++) {
            func_ov031_0223cb34(t, b, &buf);
            if (func_ov031_0223d49c(&buf)) {
                if (data_ov031_02250c00->f67 == 0) {
                    func_ov031_02236878(9);
                    return;
                }
                func_ov031_02236878(0);
                data_ov031_02250c00->status = i;
                return;
            }
        }
    }
    {
        Point16_02225f2c* b;
        Point16_02225f2c* t;
        PointPair16_02225f2c buf;
        int i;
        for (i = 0, b = &data_ov031_02248c90, t = data_ov031_02248cb0; i < 2; i++, t++) {
            func_ov031_0223cb34(t, b, &buf);
            if (func_ov031_0223d49c(&buf)) {
                if ((i == 0 && data_ov031_02250c00->f66 == 0) ||
                    (i == 1 && data_ov031_02250c00->f68 == 0)) {
                    func_ov031_02236878(9);
                    return;
                }
                func_ov031_02236878(0);
                data_ov031_02250c00->status = i + 10;
                return;
            }
        }
    }
    {
        int i;
        Point16_02225f2c* t;
        Point16_02225f2c* b;
        PointPair16_02225f2c buf;
        for (i = 0, t = data_ov031_02248cb8, b = &data_ov031_02248c94; i < 2; i++, t++) {
            func_ov031_0223cb34(t, b, &buf);
            if (func_ov031_0223d49c(&buf)) {
                func_ov031_02236878(0);
                data_ov031_02250c00->status = i + 12;
                return;
            }
        }
    }
}
