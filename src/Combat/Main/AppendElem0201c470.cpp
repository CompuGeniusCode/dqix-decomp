#include <globaldefs.h>

struct Name0201c470 { unsigned char v[31]; };
struct Elem0201c470 { struct Name0201c470 name; unsigned char flag; };
struct Obj0201c470 {
    struct Elem0201c470* base;   // 0x0
    int cap;                     // 0x4
    int count;                   // 0x8
};

// USA: func_0201c470
ARM void AppendElem0201c470(struct Obj0201c470* obj, struct Elem0201c470* src) {
    struct Elem0201c470* base = obj->base;
    if (base != NULL) {
        struct Elem0201c470* dst;
        if (obj->count >= obj->cap) return;
        dst = &base[obj->count];
        dst->name = src->name;
        dst->flag = src->flag;
        obj->count++;
        return;
    }
    obj->count++;
}
