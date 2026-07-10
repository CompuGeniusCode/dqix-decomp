#include <globaldefs.h>

void CopyVec3(int* dst, int* src);

struct Vec3PairRecord020a0d6c {
    int type;    // 0x0
    int from[3]; // 0x4
    int to[3];   // 0x10
    int f1c;     // 0x1c
    int f20;     // 0x20
    int f24;     // 0x24
};

// USA: func_020a0d6c
ARM void InitVec3PairRecordType1(struct Vec3PairRecord020a0d6c* rec, int* from, int* to, int a3, int a5, int a6) {
    CopyVec3(rec->from, from);
    CopyVec3(rec->to, to);
    rec->f1c = a3;
    rec->f20 = a5;
    rec->f24 = a6;
    if (a6 == 0) rec->f24 = a5;
    rec->type = 1;
}
