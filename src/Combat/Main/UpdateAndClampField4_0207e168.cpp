#include <globaldefs.h>

struct SubHalf02035544 {
    unsigned char pad0[4];
    unsigned short field4;
};
struct Obj02035544 {
    unsigned char pad0[8];
    struct SubHalf02035544* field8;
};
int GetScaledHalfwordFromField8(struct Obj02035544* obj);

static inline int FixedMulRound_0207e168(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

struct Obj0207e168 {
    char pad0[4];
    struct Obj02035544* field4;
    int field8;
    int fieldC;
};

// USA: func_0207e168  (semantic: UpdateAndClampField4_0207e168)
extern "C" ARM int func_0207e168(struct Obj0207e168* obj, int scale) {
    int hasField4;
    struct Obj02035544* p0;
    struct Obj02035544* ptr;
    int scaled1;
    int cur;
    int scaled;

    p0 = obj->field4;
    hasField4 = (p0 != 0);
    if (!hasField4) return hasField4;

    *(int*)p0 += FixedMulRound_0207e168(obj->field8, scale);

    ptr = obj->field4;
    scaled1 = GetScaledHalfwordFromField8(ptr);
    if (scaled1 > *(int*)ptr) {
        return scaled1;
    }

    if (obj->fieldC & 1) {
        scaled = GetScaledHalfwordFromField8(ptr);
        *(int*)obj->field4 = scaled;
        return scaled;
    }

    while (ptr = obj->field4, cur = *(int*)ptr, (scaled = GetScaledHalfwordFromField8(ptr)) <= cur) {
        *(int*)obj->field4 -= GetScaledHalfwordFromField8(ptr);
    }
    if (cur < 0) {
        *(int*)ptr = 0;
        return 0;
    }
    return scaled;
}
