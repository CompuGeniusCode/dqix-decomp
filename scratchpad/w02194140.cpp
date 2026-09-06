#include <globaldefs.h>

struct IntField0x68_020377bc;
int GetIntAt0x68(struct IntField0x68_020377bc* obj);
int GetIntAt0x64(unsigned char* obj);
int AbsInt(int x);

struct Vec3s32_020c3030;
int Distance3D020c3030(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

// USA: func_ov017_02194140
#pragma optimize_for_size off
ARM int CheckRangeOverlap_02194140(unsigned char* self, unsigned char* other) {
    int va = GetIntAt0x68((struct IntField0x68_020377bc*)self);
    int vb = GetIntAt0x68((struct IntField0x68_020377bc*)other);
    int a48 = *(int*)(self + 0x48);
    int b48 = *(int*)(other + 0x48);

    if (a48 + va < b48 || b48 + vb < a48) return 0;

    int va64 = GetIntAt0x64(self);
    int half = (GetIntAt0x64(other) >> 1) + (va64 >> 1);

    if (half < AbsInt(*(int*)(self + 0x44) - *(int*)(other + 0x44))) goto ret0;
    if (half >= AbsInt(*(int*)(self + 0x4c) - *(int*)(other + 0x4c))) {
        int dist = Distance3D020c3030((struct Vec3s32_020c3030*)(self + 0x44), (struct Vec3s32_020c3030*)(other + 0x44));
        return half >= dist;
    }
ret0:
    return 0;
}
