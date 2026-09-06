#include <globaldefs.h>

struct Mid021eee48 { unsigned int v[4]; };

struct Rec021eee48 {
    unsigned int f0;
    unsigned int f4;
    struct Mid021eee48 mid;
    struct Rec021eee48* next;
};

struct Obj021eee48 {
    char pad0[0xe0];
    struct Rec021eee48* activeHead;
    struct Rec021eee48* freeHead;
};

// USA: func_ov025_021eee48
ARM void PushNodeFromFreeList_021eee48(struct Obj021eee48* obj, struct Rec021eee48* src) {
    struct Rec021eee48* node = obj->freeHead;
    if (node == NULL) {
        return;
    }
    struct Rec021eee48* savedNext = node->next;
    node->f0 = src->f0;
    node->f4 = src->f4;
    node->mid = src->mid;
    node->next = src->next;
    obj->freeHead = savedNext;
    node->next = obj->activeHead;
    obj->activeHead = node;
}
