#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
struct TaggedValue02030b44;
float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);
extern "C" void func_ov000_02169b78(void* p);

struct Data02184264 {
    char pad0[0x8];
    SafeAllocator* alloc;
};
extern struct Data02184264 data_ov000_02184264;

// USA: func_ov000_0216a9dc
ARM int BuildEventFromVariantList0216a9dc(char* obj, int count) {
    char* p = (char*)data_ov000_02184264.alloc->Allocate(0xc);
    *(int*)(p + 0x0) = 0;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x0) = 0x1a;

    int idx = 1;
    int tag = *(int*)obj;
    if (tag == 2) {
        *(unsigned char*)(p + 0x8) = 7;
        *(unsigned short*)(p + 0xa) = 0x1000;
    } else if (tag == 1) {
        int val = GetIntFromVariant02030b0c((struct Variant02030b0c*)obj);
        *(unsigned char*)(p + 0x8) = (unsigned char)val;
        *(unsigned short*)(p + 0xa) = 0x1000;
        obj += 8;
        idx = 2;
    }

    if (idx <= count) {
        int tag2 = *(int*)obj;
        if (tag2 == 2) {
            float f = GetTaggedValueAsFloat((struct TaggedValue02030b44*)obj);
            *(unsigned short*)(p + 0xa) = (unsigned short)(int)(f * 4096.0f);
        } else if (tag2 == 1) {
            int v = GetIntFromVariant02030b0c((struct Variant02030b0c*)obj);
            float vf = (float)v;
            *(unsigned short*)(p + 0xa) = (unsigned short)(int)((vf / 1000.0f) * 4096.0f);
        }
    }

    func_ov000_02169b78(p);
    return 1;
}
