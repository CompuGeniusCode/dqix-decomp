#include <globaldefs.h>

struct ShortVec3Quad02031188 {
    short v[12];
};

struct S020311e8;
void SetThreeFields020311e8(struct S020311e8*, int, int, int);

// USA: func_02031188
ARM void ExpandShortVec3Quad(void* dst, struct ShortVec3Quad02031188* src) {
    SetThreeFields020311e8((struct S020311e8*)((char*)dst + 0x24), src->v[9], src->v[10], src->v[11]);
    SetThreeFields020311e8((struct S020311e8*)(dst), src->v[0], src->v[1], src->v[2]);
    SetThreeFields020311e8((struct S020311e8*)((char*)dst + 0xc), src->v[3], src->v[4], src->v[5]);
    SetThreeFields020311e8((struct S020311e8*)((char*)dst + 0x18), src->v[6], src->v[7], src->v[8]);
}
