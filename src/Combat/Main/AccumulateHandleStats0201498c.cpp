#include <globaldefs.h>

struct Obj0207a6a4;
int UpdateHandleState0207a6a4(struct Obj0207a6a4* obj);

extern "C" void func_0207a734(void* a, void* b, int c, int d);

int GetFieldAt0x00207b000(int* obj);
int GetField0x580207ecc4(void* obj);

struct ScaledField020b2e3c;
int GetScaledField0xc(struct ScaledField020b2e3c* s);

unsigned int GetScaledHalfword0x30(unsigned char* obj);

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
            int val = GetField0x580207ecc4(p);
            if (val != 0) {
                *(int*)(obj + 0x838) += GetScaledField0xc((struct ScaledField020b2e3c*)val);
                *(int*)(obj + 0x83c) += (int)GetScaledHalfword0x30((unsigned char*)val);
            }
        }
        node = *(void**)((char*)node + 0x100);
    }
    return 1;
}
