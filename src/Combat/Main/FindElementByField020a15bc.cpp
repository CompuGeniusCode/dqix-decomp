#include <globaldefs.h>

struct Elem020a15bc {
    unsigned int field : 9;
    unsigned int pad : 23;
    unsigned int w1;
    unsigned int w2;
};

struct Array020a15bc {
    struct Elem020a15bc* base;
    unsigned short pad4;
    unsigned short count;
};

// USA: func_020a15bc
ARM struct Elem020a15bc* FindElementByField020a15bc(struct Array020a15bc* arr, int id) {
    unsigned short key;
    int i;
    if (id <= 0) {
        return NULL;
    }
    key = (unsigned short)id;
    for (i = 0; i < arr->count; i++) {
        if (key == arr->base[i].field) {
            return &arr->base[i];
        }
    }
    return NULL;
}
