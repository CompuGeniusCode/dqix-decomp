#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Vec3Fixed02030e2c {
    int x;
    int y;
    int z;
};

struct Struct02041538;

void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
int Vec3LengthRounded(int* v);
void CopyVec3(int* dst, int* src);
int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);
void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);
void RefreshSelectionState02041538(struct Struct02041538* self);

struct MoveObj020412f4 {
    char pad0[0x44];
    struct Vec3 pos;       // 0x44
    char pad1[0xb4 - 0x50];
    struct Vec3 target;    // 0xb4
    char pad2[0xc8 - 0xc0];
    int step;              // 0xc8
};

// USA: func_020412f4  (semantic: AdvanceTowardOrSnap020412f4)
extern "C" ARM void func_020412f4(struct MoveObj020412f4* obj) {
    struct Vec3 diff;
    SubtractVec3(&obj->target, &obj->pos, &diff);
    int length = Vec3LengthRounded((int*)&diff);
    if (obj->step < length) {
        int scale = HwDivideRounded020c2bf4(obj->step, length);
        ScaleVec3Fixed02030e2c((struct Vec3Fixed02030e2c*)&diff, scale, (struct Vec3Fixed02030e2c*)&diff);
        struct Vec3 sum;
        AddVec3(&obj->pos, &diff, &sum);
        CopyVec3((int*)&obj->pos, (int*)&sum);
    } else {
        CopyVec3((int*)&obj->pos, (int*)&obj->target);
        RefreshSelectionState02041538((struct Struct02041538*)obj);
    }
}
