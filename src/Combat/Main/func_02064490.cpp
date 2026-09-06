#include <globaldefs.h>

struct Node02064704 {
    char pad0[0xc];
    struct Node02064704* next;
};

struct Node02064490 {
    char pad0[6];
    unsigned char byte6;
    char pad7;
    struct Node02064704* field8;
    char pad0xc[4];
    struct Node02064490* field10;
    struct Node02064490* field14;
};

struct Obj02064490 {
    char pad0[0x47c];
    struct Node02064490* list47c;
    char pad0x480[0x492 - 0x480];
    unsigned char byte492;
};

extern "C" int func_0205faf4(void*, struct Node02064704*, void*);

// USA: func_02064490
extern "C" ARM struct Node02064490* func_02064490(struct Obj02064490* obj, int key, void* extra) {
    struct Node02064490* node;
    for (node = obj->list47c; node != NULL; node = node->field14) {
        if (node->byte6 == key) break;
    }
    if (node == NULL) return NULL;
    obj->byte492 = 0;
    int ok = 1;
    struct Node02064704* inner;
    for (; node != NULL; node = node->field10) {
        for (inner = node->field8; inner != NULL; inner = inner->next) {
            if (func_0205faf4(obj, inner, extra) == 0) {
                ok = 0;
                break;
            }
            ok = 1;
        }
        if (ok) return node;
    }
    return NULL;
}
