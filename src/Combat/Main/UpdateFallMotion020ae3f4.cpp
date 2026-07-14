#include <globaldefs.h>

void CopyVec3(int* dst, int* src);

struct Obj020ae3f4 {
    char pad0[0x44];
    int position[3];   // 0x44
    char pad1[0x140 - 0x50];
    int counter;        // 0x140
    char pad2[0x168 - 0x144];
    int field168;        // 0x168
    char pad3[0x178 - 0x16c];
    int field178;        // 0x178
};

// USA: func_020ae3f4
ARM void UpdateFallMotion020ae3f4(struct Obj020ae3f4* obj) {
    int count = obj->counter + 1;
    obj->counter = count;
    int factor = count * count;
    int localVec[3];
    CopyVec3(localVec, obj->position);
    localVec[1] += (int)(((float)factor * 0.005f) * 4096.0f);
    CopyVec3(obj->position, localVec);
    obj->field168 += (int)(((float)factor * 0.005f) * 4096.0f);
    obj->field178 += (int)(((float)factor * 0.005f) * 4096.0f);
}
