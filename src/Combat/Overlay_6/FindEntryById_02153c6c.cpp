#include <globaldefs.h>

struct Entry02153c6c {
    short id;
    short pad;
};

struct Obj02153c6c {
    unsigned char pad0[0x20];
    struct Entry02153c6c* arr;
    unsigned short count;
};

// USA: func_ov006_02153c6c  (semantic: FindEntryById_02153c6c)
extern "C" ARM struct Entry02153c6c* func_ov006_02153c6c(struct Obj02153c6c* obj, int id) {
    if (id < 0) return 0;
    unsigned short count = obj->count;
    for (unsigned short i = 0; i < count; i++) {
        struct Entry02153c6c* arr = obj->arr;
        short v = arr[i].id;
        if (v == id) return &arr[i];
    }
    return 0;
}
