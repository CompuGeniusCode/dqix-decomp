#include <globaldefs.h>

struct VecBlk3_02164808 { int v[3]; };
struct VecBlk3_02164808 GetVec3FromShortsAt0x5c(unsigned char* src);

struct Entry02164808 { int selector; char pad[8]; unsigned char* target; };
struct Vec3Out02164808 { int x, y, z; };

// USA: func_ov001_02164808  (semantic: GetVec3FromEntry_02164808)
extern "C" ARM int func_ov001_02164808(struct Entry02164808* arr, int index, struct Vec3Out02164808* out) {
    struct VecBlk3_02164808 resultA;
    struct VecBlk3_02164808 resultB;
    struct VecBlk3_02164808 tmpA;
    struct VecBlk3_02164808 tmpB;
    struct Entry02164808* e;
    unsigned char* t;
    unsigned char* src;

    if (index < 0 || index >= 0x20) {
        return 0;
    }
    e = &arr[index];
    switch (e->selector) {
    case 0:
    case 1:
    case 4:
    case 5:
        t = e->target;
        if (t == NULL) return 0;
        tmpA = GetVec3FromShortsAt0x5c(t);
        resultA = tmpA;
        out->x = resultA.v[0];
        out->y = resultA.v[1];
        out->z = resultA.v[2];
        return 1;
    case 6:
        t = e->target;
        if (t == NULL) return 0;
        src = *(unsigned char**)(t + 0x18);
        if (src == NULL) return 0;
        tmpB = GetVec3FromShortsAt0x5c(src);
        resultB = tmpB;
        out->x = resultB.v[0];
        out->y = resultB.v[1];
        out->z = resultB.v[2];
        return 1;
    }
    return 0;
}
