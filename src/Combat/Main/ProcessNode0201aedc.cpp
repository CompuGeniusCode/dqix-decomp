#include <globaldefs.h>

int IsValueInRange0201b5d8(int x);

struct Obj020196fc;
struct Node020196fc;
Node020196fc* GetNodeAtDepth020196fc(Obj020196fc* obj, int count);

void* GetData02107930(void);

struct Obj02052338;
int Forward02052338(Obj02052338* obj, int arg1);

void ClearGlobalFlagBits02016d8c(void* arg0);

struct Vec3Block020b3850;
void StoreVec3AndClearFlags020b3850(Vec3Block020b3850* src);

void InvokeHandlerAndClearFlags020b3814(void);

extern "C" void func_0207e87c(void* a, int b);

struct Ctx0201aedc { unsigned short field0; };

// USA: func_0201aedc
ARM void ProcessNode0201aedc(Ctx0201aedc* p) {
    if (IsValueInRange0201b5d8(p->field0)) return;

    char* buf = (char*)p + 0x25b4;

    Node020196fc* node = GetNodeAtDepth020196fc((Obj020196fc*)p, 5);
    if (node != 0) {
        void* ptr1 = *(void**)((char*)node + 0x44);
        unsigned short flags = *(unsigned short*)((char*)ptr1 + 2);
        if (!(flags & 4)) {
            void* ptr2 = *(void**)((char*)ptr1 + 0x24);
            void* r6 = *(void**)((char*)ptr2 + 4);
            if (r6 != 0 && *(int*)((char*)r6 + 0x54) != 0) {
                void* obj = GetData02107930();
                int arg1 = *(int*)((char*)r6 + 0x54);
                Forward02052338((Obj02052338*)obj, arg1);
                ClearGlobalFlagBits02016d8c(buf + 0x48);
                StoreVec3AndClearFlags020b3850((Vec3Block020b3850*)(buf + 0x6c));
                InvokeHandlerAndClearFlags020b3814();
                func_0207e87c(r6, 1);
            }
        }
    }

    Node020196fc* node2 = GetNodeAtDepth020196fc((Obj020196fc*)p, 4);
    if (node2 == 0) return;
    void* ptr1b = *(void**)((char*)node2 + 0x44);
    unsigned short flagsb = *(unsigned short*)((char*)ptr1b + 2);
    if (flagsb & 4) return;
    void* ptr2b = *(void**)((char*)ptr1b + 0x24);
    void* r5v = *(void**)((char*)ptr2b + 4);
    if (r5v != 0 && *(int*)((char*)r5v + 0x54) != 0) {
        void* obj2 = GetData02107930();
        int arg1b = *(int*)((char*)r5v + 0x54);
        Forward02052338((Obj02052338*)obj2, arg1b);
        ClearGlobalFlagBits02016d8c(buf + 0x14);
        StoreVec3AndClearFlags020b3850((Vec3Block020b3850*)(buf + 0x38));
        InvokeHandlerAndClearFlags020b3814();
        func_0207e87c(r5v, 1);
    }
}
