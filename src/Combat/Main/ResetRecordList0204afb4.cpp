#include <globaldefs.h>

struct Struct0204a82c;
struct Record0204acb0 { unsigned char pad[0x10]; };
void ClearStruct0204a82c(struct Struct0204a82c* s);
void ClearRecordFields(struct Record0204acb0* rec);

struct List0204afb4 {
    unsigned char pad0[0xc];
    unsigned char fc;              // 0xc
    unsigned char pad_d;           // 0xd
    unsigned short fe;             // 0xe
    struct Record0204acb0* f10;    // 0x10
    int f14;                       // 0x14
    unsigned char pad18[0x5];      // 0x18..0x1c
    unsigned char f1d;             // 0x1d
};

// USA: func_0204afb4
ARM void ResetRecordList0204afb4(struct List0204afb4* obj) {
    unsigned char i;
    obj->f14 = 0;
    ClearStruct0204a82c((struct Struct0204a82c*)obj);
    obj->fc = 0;
    obj->fe = 0xffff;
    if (obj->f10 == 0) return;
    i = 0;
    while (i < obj->f1d) {
        ClearRecordFields(&obj->f10[i]);
        i++;
    }
}
