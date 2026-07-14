#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
void CopyVec3(int* dst, int* src);

ARM int Vec3LengthRounded(int* v);
ARM int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);

struct Vec3Fixed02030e2c { int x; int y; int z; };
ARM void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

// USA: func_02033e38
ARM void AdjustPositionTowardTarget02033e38(void* obj) {
    char* base = (char*)obj;
    short* speedPtr = (short*)(base + 0xc6);
    short speed = *speedPtr;
    if (speed != 0) {
        struct Vec3 diff;
        SubtractVec3((struct Vec3*)(base + 0xc8), (struct Vec3*)(base + 0x44), &diff);
        int dist = Vec3LengthRounded((int*)&diff);
        if (dist < speed) {
            CopyVec3((int*)(base + 0x44), (int*)(base + 0xc8));
            *speedPtr = 0;
        } else {
            int scale = HwDivideRounded020c2bf4(speed, dist);
            ScaleVec3Fixed02030e2c((struct Vec3Fixed02030e2c*)&diff, scale, (struct Vec3Fixed02030e2c*)&diff);
            struct Vec3 sum;
            AddVec3((struct Vec3*)(base + 0x44), &diff, &sum);
            CopyVec3((int*)(base + 0x44), (int*)&sum);
        }
    }
}
