#include <globaldefs.h>

struct Node0215fe00 {
    char pad0[4];
    struct Node0215fe00* next;
};
struct Obj0215fe00 {
    char pad0[8];
    struct Node0215fe00* head;
    char pad1[0x13];
    unsigned char count;
};

// USA: func_ov000_0215fe00
ARM void AppendNode0215fe00(struct Obj0215fe00* obj, struct Node0215fe00* newNode) {
    struct Node0215fe00** p = &obj->head;
    while (*p != NULL) {
        p = &(*p)->next;
    }
    *p = newNode;
    obj->count++;
}
