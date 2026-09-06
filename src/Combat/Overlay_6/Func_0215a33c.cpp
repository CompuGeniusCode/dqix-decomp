#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void func_ov006_02156e54(void* p);
extern int data_020f2a38;
extern int data_020f2a30;

struct Obj0215a33c {
    char pad0[0x10];
    void* field10;
    char pad14[0x354 - 0x14];
    int field354;
};

// USA: func_ov006_0215a33c
ARM void Func_0215a33c(struct Obj0215a33c* obj) {
    int a;
    func_ov006_02156e54(obj->field10);
    a = (int)BackgroundLoader::GetInstance();
    ((BackgroundLoader*)((unsigned char*)a))->AddFence();
    obj->field354 = ((BackgroundLoader*)(a))->QueueLoadFileInGP2((const char*)(data_020f2a38), (const char*)(data_020f2a30), (SafeAllocator*)(0));
}
