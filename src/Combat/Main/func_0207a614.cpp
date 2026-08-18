#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern char data_020f0ea0;

struct Struct0207a614 {
    char pad0[4];
    int field4;
    int field8;
    int fieldc;
    unsigned char field10;
    unsigned char pad11;
    unsigned char field12;
    unsigned char field13;
    unsigned char field14;
};

// USA: func_0207a614
extern "C" ARM void func_0207a614(struct Struct0207a614* obj, int b) {
    char buf[0x50];
    int val = (int)BackgroundLoader::GetInstance();
    sprintf(buf, &data_020f0ea0, b);
    obj->field4 = ((BackgroundLoader*)(val))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
    obj->field10 = 1;
    obj->field8 = 0;
    obj->fieldc = 0;
    obj->field13 = 0x1f;
    obj->field12 = 0;
    obj->field14 &= ~0x3;
    obj->field14 &= ~0x4;
    obj->field14 &= ~0x78;
    obj->field14 |= 0x80;
}
