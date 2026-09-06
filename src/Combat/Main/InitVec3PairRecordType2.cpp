#include <globaldefs.h>

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Vec3PairRecord020a0db8 {
    int type;    // 0x0
    int from[3]; // 0x4
    int to[3];   // 0x10
    int pad;     // 0x1c
    int f20;     // 0x20
    int f24;     // 0x24
};

// USA: func_020a0db8
ARM void InitVec3PairRecordType2(struct Vec3PairRecord020a0db8* rec, int* from, int* to, int a3) {
    _ZN8Vector3iaSERKS_(rec->from, from);
    _ZN8Vector3iaSERKS_(rec->to, to);
    rec->f24 = a3;
    rec->type = 2;
}
