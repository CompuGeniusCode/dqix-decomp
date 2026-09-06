#include <globaldefs.h>

extern "C" void __clear(void* buf, int size);
extern "C" int func_020426bc(void* src, void* buf, int flag);
extern "C" int func_02001aec(void* entry, void* param1, int category);
extern "C" void func_0203bebc(void* entry, void* buf, void* dest);

struct Entry0203c5a8 {
    char pad[0x20];
    unsigned char category;
    char pad2[3];
    unsigned char inUse;
    char pad3[3];
};

// USA: func_0203c5a8  (semantic: FindOrAllocateSlot0203c5a8)
extern "C" ARM void func_0203c5a8(void* self, void* param1, short* outIndex) {
    if (param1 == 0) return;
    char buf[0x100];
    __clear(buf, 0x100);
    int category = func_020426bc(param1, buf, 0);

    struct Entry0203c5a8* entry = (struct Entry0203c5a8*)((char*)self + 4);
    for (short i = 0; i < 0x20; entry = (struct Entry0203c5a8*)((char*)entry + 0x28), i++) {
        if (entry->inUse != 0 && entry->category == category) {
            if (func_02001aec(entry, buf, category) == 0) {
                entry->inUse = entry->inUse + 1;
                *outIndex = i;
                return;
            }
        }
    }

    entry = (struct Entry0203c5a8*)((char*)self + 4);
    for (short j = 0; j < 0x20; entry = (struct Entry0203c5a8*)((char*)entry + 0x28), j++) {
        if (entry->inUse == 0) {
            unsigned short counter = *(unsigned short*)((char*)self + 0x512);
            void* table = *(void**)((char*)self + 0x508);
            counter = counter + 1;
            *(unsigned short*)((char*)self + 0x512) = counter;
            entry->inUse = 1;
            entry->category = (unsigned char)category;
            func_0203bebc(entry, buf, (char*)table + j * 0x400);
            *outIndex = j;
            return;
        }
    }
}
