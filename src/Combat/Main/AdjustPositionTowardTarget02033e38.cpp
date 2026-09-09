#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

extern "C" ARM int Vector3fix_Length(int* v);
extern "C" ARM int fix32_Divide(unsigned int numerHi, unsigned int denomLo);

struct Vec3Fixed02030e2c { int x; int y; int z; };
extern "C" ARM void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

// USA: func_02033e38
ARM void AdjustPositionTowardTarget02033e38(void* obj) {
    char* base = (char*)obj;
    short* speedPtr = (short*)(base + 0xc6);
    short speed = *speedPtr;
    if (speed != 0) {
        struct Vec3 diff;
        Vector3fix_Subtract((struct Vec3*)(base + 0xc8), (struct Vec3*)(base + 0x44), &diff);
        int dist = Vector3fix_Length((int*)&diff);
        if (dist < speed) {
            _ZN8Vector3iaSERKS_((int*)(base + 0x44), (int*)(base + 0xc8));
            *speedPtr = 0;
        } else {
            int scale = fix32_Divide(speed, dist);
            _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_((struct Vec3Fixed02030e2c*)&diff, scale, (struct Vec3Fixed02030e2c*)&diff);
            struct Vec3 sum;
            Vector3fix_Add((struct Vec3*)(base + 0x44), &diff, &sum);
            _ZN8Vector3iaSERKS_((int*)(base + 0x44), (int*)&sum);
        }
    }
}
