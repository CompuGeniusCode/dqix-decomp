#include <globaldefs.h>

struct Entry_02211f24 {
    int field0;
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned short field0xa;
    unsigned char field0xc;
    unsigned char pad0xd[3];
    int field0x10;
};

struct Glob0224e5b4_02211f24 {
    int field0;
    Entry_02211f24* field4;
};
extern Glob0224e5b4_02211f24 data_ov031_0224e5b4;

extern "C" ARM void func_ov031_02211e08(void);
void SetGlobal0224e5a4IfNotNine(int, int);
int ClassifyField9_02212fb8(void);
int GetGlobal022496fcField4_02207cd0(void);
extern "C" ARM void func_ov031_022120f8(void);
extern "C" ARM void func_ov031_02211bd4(Entry_02211f24*, unsigned short, int, int);
extern "C" ARM int func_ov031_022162f0(void*, int);

#pragma optimize_for_size off
// USA: func_ov031_02211f24
extern "C" ARM int func_ov031_02211f24(void) {
    int v;
    Entry_02211f24* q = data_ov031_0224e5b4.field4;
    if (q == 0) return 0;

    switch (q->field0x10) {
    case 1:
        return 2;
    case 2:
        return 2;
    case 3:
        func_ov031_02211e08();
        SetGlobal0224e5a4IfNotNine(5, data_ov031_0224e5b4.field0);
        data_ov031_0224e5b4.field4->field4 = 7;
        data_ov031_0224e5b4.field4->field0x10 = 4;
        return 7;
    case 4:
        return 7;
    case 5:
        return 5;
    default:
        break;
    }

    unsigned short f4 = q->field4;
    if (f4 == 1) return f4;

    v = ClassifyField9_02212fb8();
    if (v == 5) {
        data_ov031_0224e5b4.field4->field4 = 4;
        data_ov031_0224e5b4.field4->field6 = 1;
        data_ov031_0224e5b4.field4->field0xc = 1;
        return 4;
    }
    if (v < 0) {
        if (v < -10) {
            Entry_02211f24* q2 = data_ov031_0224e5b4.field4;
            if (q2->field0xc != 0) {
                int threshold = data_ov031_0224e5b4.field0;
                if (threshold < v) v = threshold;
                SetGlobal0224e5a4IfNotNine(5, v);
                data_ov031_0224e5b4.field4->field4 = 7;
                return 7;
            }
            unsigned short w = q2->field8;
            int g = GetGlobal022496fcField4_02207cd0();
            data_ov031_0224e5b4.field0 = v;
            func_ov031_022120f8();
            func_ov031_02211bd4(q2, w, 1, (unsigned short)g);
            func_ov031_022162f0((char*)data_ov031_0224e5b4.field4 + 0x14, 1);
            data_ov031_0224e5b4.field4->field0x10 = 1;
            data_ov031_0224e5b4.field4->field0 = 0;
            return 2;
        }
        data_ov031_0224e5b4.field4->field0xc = 1;
        SetGlobal0224e5a4IfNotNine(9, (int)0xffff3be9);
        data_ov031_0224e5b4.field4->field4 = 8;
        return 8;
    }
    return 2;
}
