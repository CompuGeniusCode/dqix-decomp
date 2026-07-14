#include <globaldefs.h>

struct Outer020bec80;
void ClearInnerField14c020bec80(struct Outer020bec80* p);
extern "C" void func_020bf1a0(void* entry);

struct Entry020bee20 { unsigned char _pad[0x174]; };
extern struct Entry020bee20 data_02110a4c[];

struct Flags0x110_020bee20 { int active : 1; };

// USA: func_020bee20
ARM void* AttachOrRefreshEntry(void** self, int index, int value) {
    if (*self != NULL) {
        ClearInnerField14c020bec80((struct Outer020bec80*)self);
    }
    unsigned char* entry = (unsigned char*)&data_02110a4c[index];
    if (*(void**)(entry + 0x12c) == NULL) {
        return NULL;
    }
    if (((struct Flags0x110_020bee20*)(entry + 0x110))->active) {
        if (value < *(int*)(entry + 0x150)) {
            return NULL;
        }
        func_020bf1a0(entry);
    }
    *(int*)(entry + 0x150) = value;
    ((struct Flags0x110_020bee20*)(entry + 0x110))->active = 1;
    *(void**)(entry + 0x14c) = self;
    *self = entry;
    return entry;
}
