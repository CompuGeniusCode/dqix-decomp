#include <globaldefs.h>

struct Obj0207a6a4;
int UpdateHandleState0207a6a4(struct Obj0207a6a4* obj);

extern "C" void func_0207a734(void* a, void* b, int c, int d);

int GetFieldAt0x00207b000(int* obj);
extern "C" int _ZN7Model3D7GetTEX0Ev(void* obj);

struct ScaledField020b2e3c;
extern "C" int NSBXX_Tex_GetBlock1Length(struct ScaledField020b2e3c* s);

extern "C" unsigned int NSBXX_Tex_GetBlock4Length(unsigned char* obj);

// USA: func_0201498c
ARM int AccumulateHandleStats0201498c(void* objRaw) {
    unsigned char* obj = (unsigned char*)objRaw;
    struct Obj0207a6a4* handle = (struct Obj0207a6a4*)(obj + 0xf4);

    if (!UpdateHandleState0207a6a4(handle)) {
        return 0;
    }

    func_0207a734(handle, handle, *(int*)(obj + 0x68), *(int*)(obj + 0x50));

    void* node = (void*)GetFieldAt0x00207b000((int*)handle);
    while (node != NULL) {
        void* p = *(void**)((char*)node + 0x8);
        if (p != NULL) {
            int val = _ZN7Model3D7GetTEX0Ev(p);
            if (val != 0) {
                *(int*)(obj + 0x838) += NSBXX_Tex_GetBlock1Length((struct ScaledField020b2e3c*)val);
                *(int*)(obj + 0x83c) += (int)NSBXX_Tex_GetBlock4Length((unsigned char*)val);
            }
        }
        node = *(void**)((char*)node + 0x100);
    }
    return 1;
}
