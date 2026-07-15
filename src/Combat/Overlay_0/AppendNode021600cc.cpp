#include <globaldefs.h>

struct Node021600cc {
    char pad0[0x20];
    struct Node021600cc* next;
};
struct Obj021600cc {
    char pad0[9];
    unsigned char count;
    char pad1[0xa];
    struct Node021600cc* head;
};

// USA: func_ov000_021600cc
ARM void AppendNode021600cc(struct Obj021600cc* obj, struct Node021600cc* newNode) {
    struct Node021600cc** p = &obj->head;
    while (*p != NULL) {
        p = &(*p)->next;
    }
    *p = newNode;
    obj->count++;
}
