#include <globaldefs.h>

struct Vec3s32_020c3030 { int x; int y; int z; };
extern "C" int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

extern "C" void __clear(void* ptr, int size);

struct Obj020968d0 {
    unsigned char pad[0x220];
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char flag;
};

// USA: func_020968d0
ARM int CheckAndComputeDistance020968d0(struct Obj020968d0* obj, int* outDist) {
    int v0, v1, v2, v3;
    int dist;
    struct Vec3s32_020c3030 a, b;
    int scaled;
    float f;

    if (obj->flag == 0) {
        return 0;
    }

    scaled = (int)obj->b0 << 12;
    if (obj->b0 != 0) f = 0.5f + (float)scaled;
    else f = (float)scaled - 0.5f;
    v0 = (int)f;

    scaled = (int)obj->b1 << 12;
    if (obj->b1 != 0) f = 0.5f + (float)scaled;
    else f = (float)scaled - 0.5f;
    v1 = (int)f;

    scaled = (int)obj->b2 << 12;
    if (obj->b2 != 0) f = 0.5f + (float)scaled;
    else f = (float)scaled - 0.5f;
    v2 = (int)f;

    scaled = (int)obj->b3 << 12;
    if (obj->b3 != 0) f = 0.5f + (float)scaled;
    else f = (float)scaled - 0.5f;
    v3 = (int)f;

    __clear(&a, 0xc);
    a.x = v0;
    a.y = v1;
    __clear(&b, 0xc);
    b.x = v2;
    b.y = v3;

    dist = Vector3fix_Distance(&a, &b);
    if (outDist != NULL) *outDist = dist;
    if (dist < 0x8000) return 0;
    return 1;
}
