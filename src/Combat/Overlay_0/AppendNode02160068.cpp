#include <globaldefs.h>

struct Node02160068 {
    char pad0[0x30];
    struct Node02160068* next;
};
struct Obj02160068 {
    char pad0[8];
    unsigned char count;
    char pad1[7];
    struct Node02160068* head;
};

// USA: func_ov000_02160068
ARM void AppendNode02160068(struct Obj02160068* obj, struct Node02160068* newNode) {
    struct Node02160068** p = &obj->head;
    while (*p != NULL) {
        p = &(*p)->next;
    }
    *p = newNode;
    obj->count++;
}
