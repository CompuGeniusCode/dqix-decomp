#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" void* func_ov017_0218b5b0(void);

struct Vec3s32_020c3030 { int x; int y; int z; };
int Distance3D020c3030(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

extern "C" int _s32_div_f(int a, int b);
void CopyVec3(int* dst, int* src);

struct Vec3 { int x; int y; int z; };

struct Obj020a7ce0 {
    char pad0[0x44];
    struct Vec3 vec44;
    char pad1[0x144 - 0x50];
    struct Vec3 vec144;
    int dist150;
};

// USA: func_020a7ce0  (semantic: AccumulateDistanceAndDecay020a7ce0)
extern "C" ARM void func_020a7ce0(struct Obj020a7ce0* p) {
    void* ctx = func_02012fe4();
    void* ov = func_ov017_0218b5b0();
    char* g = (char*)ov + 0x3000;
    void* g734 = *(void**)(g + 0x734);
    if (((unsigned char*)g734)[3] != 0) return;

    struct Vec3 local = p->vec44;
    int dist = Distance3D020c3030((struct Vec3s32_020c3030*)&local, (struct Vec3s32_020c3030*)&p->vec144);
    p->dist150 += dist;
    if (p->dist150 >= 0x3000) {
        int q = _s32_div_f(p->dist150, 0x3000);
        char* base = (char*)ctx + 0x2000;
        *(int*)(base + 0x794) -= q;
        p->dist150 -= q << 12;
    }
    CopyVec3((int*)&p->vec144, (int*)&local);
}
