#include <globaldefs.h>

struct SrcVec02157570 {
    unsigned char pad0[0x38c];
    int x;
    int y;
    int z;
};
struct DstVec02157570 {
    int x;
    int y;
    int z;
};

// USA: func_ov001_02157570
ARM void CopyVector3_02157570(struct SrcVec02157570* src, struct DstVec02157570* dst) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
