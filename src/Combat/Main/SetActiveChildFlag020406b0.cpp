#include <globaldefs.h>

void SetFlag0x6cBit0(unsigned char* obj);

struct Node020406b0 {
    char pad[0x14];
    void* f14;
    void* f18;
    void* f1c;
};

// USA: func_020406b0
ARM void SetActiveChildFlag020406b0(struct Node020406b0* obj) {
    if (obj->f14 != NULL) {
        *(unsigned int*)((char*)obj->f14 + 0x50) |= 1;
        return;
    }
    if (obj->f18 != NULL) {
        SetFlag0x6cBit0((unsigned char*)obj->f18);
        return;
    }
    if (obj->f1c != NULL) {
        SetFlag0x6cBit0((unsigned char*)obj->f1c);
    }
}
