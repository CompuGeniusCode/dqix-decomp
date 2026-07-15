#include <globaldefs.h>

struct Elem021fa03c { char pad0[2]; unsigned char flag; char pad1[0x25]; };
struct Obj021fa03c {
    char pad0[0x20];
    unsigned short count;
    char pad1[2];
    struct Elem021fa03c* arr;
};

// USA: func_ov023_021fa03c
ARM struct Elem021fa03c* FindFreeSlot_021fa03c(struct Obj021fa03c* obj) {
    int i;
    for (i = 0; i < obj->count; i++) {
        struct Elem021fa03c* e = &obj->arr[i];
        if (e->flag == 0) return e;
    }
    return NULL;
}
