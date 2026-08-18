#include <globaldefs.h>

struct Entry02153e8c { short f0; short f1; };

struct Obj02153e8c {
    char pad[0x20];
    struct Entry02153e8c* arr;
    unsigned short count;
};

struct Key02153e8c { short a; short b; };

// USA: func_ov006_02153e8c  (semantic: FindOrInsertEntry_02153e8c)
extern "C" ARM void func_ov006_02153e8c(struct Obj02153e8c* obj, struct Key02153e8c* key) {
    short keyA = key->a;
    unsigned short count = obj->count;
    unsigned short i;
    for (i = 0; i < count; i++) {
        struct Entry02153e8c* e = obj->arr + i;
        if (e->f0 == keyA) {
            e->f0 = *(short*)key;
            e->f1 = *(unsigned short*)((char*)key + 2);
            return;
        }
    }
    for (i = 0; i < count; i++) {
        struct Entry02153e8c* e = obj->arr + i;
        if (e->f0 <= 0) {
            e->f0 = *(short*)key;
            e->f1 = *(unsigned short*)((char*)key + 2);
            return;
        }
    }
}
