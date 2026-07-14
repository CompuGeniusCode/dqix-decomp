#include <globaldefs.h>

void CopyVec3(int* dst, int* src);
void ApplyVec3Tail(void* obj, int* vec);
struct GlobalObj0202e6a8;
void ApplyField0x70Tail(struct GlobalObj0202e6a8*, int);
extern "C" void func_020a212c(void* obj, int flag);

struct Vec3i020a2b38 {
    int x, y, z;
};

// USA: func_020a2b38
ARM void CaptureAndApplyVecs020a2b38(void* objRaw, int* a, int* b, int* c) {
    char* base = (char*)objRaw;
    struct Vec3i020a2b38 local1 = *(struct Vec3i020a2b38*)(base + 0x10);
    struct Vec3i020a2b38 local0 = *(struct Vec3i020a2b38*)(base + 0x70);
    int v = *(short*)(base + 0x21e);
    ApplyField0x70Tail((struct GlobalObj0202e6a8*)objRaw, v);
    *(int*)(base + 0x220) = *(short*)(base + 0x21e);
    ApplyVec3Tail(objRaw, (int*)(base + 0x220));
    func_020a212c(objRaw, 0);
    CopyVec3(a, (int*)(base + 0x4));
    CopyVec3(b, (int*)(base + 0x10));
    CopyVec3(c, (int*)(base + 0x70));
    CopyVec3((int*)(base + 0x10), (int*)&local1);
    ApplyVec3Tail(objRaw, (int*)&local0);
}
