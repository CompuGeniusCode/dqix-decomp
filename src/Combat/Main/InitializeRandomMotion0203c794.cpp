#include <globaldefs.h>

extern "C" int rand(void);
extern "C" void func_0203ef7c(void*);

// USA: func_0203c794
ARM void InitializeRandomMotion0203c794(void* obj) {
    func_0203ef7c(obj);
    *(int*)((char*)obj + 0x60) = 0;
    *(int*)((char*)obj + 0x64) = 0;
    *(int*)((char*)obj + 0x68) = 0x324;
    *(int*)((char*)obj + 0x84) = (int)(((float)(rand() % 200) / 100.0f) * 4096.0f);
    *(int*)((char*)obj + 0x5c) = 0;
    *(int*)((char*)obj + 0x88) = 0;
    *(int*)((char*)obj + 0x8c) = 0x7a;
    *(int*)((char*)obj + 0x90) = 0;
    *(unsigned char*)((char*)obj + 0x94) = 0xf;
    *(unsigned char*)((char*)obj + 0x95) = 0;
    *(int*)((char*)obj + 0x98) = 0;
}
