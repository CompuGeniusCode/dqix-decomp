#include <globaldefs.h>

struct Elem020a45a0 {
    unsigned short value;
    unsigned char key;
    unsigned char sub;
};

struct Obj020a45a0 {
    unsigned char pad[0x46];
    unsigned char count;
    unsigned char pad47;
    struct Elem020a45a0 arr[1];
};

// USA: func_020a45a0
ARM unsigned short FindValueByKeyAndMode020a45a0(struct Obj020a45a0* obj, int key, int mode) {
    int i;
    struct Elem020a45a0* e;
    for (i = 0; i < obj->count; i++) {
        e = &obj->arr[i];
        if (e->key == key) {
            if (mode == 0) {
                if (e->sub == 0) return e->value;
            } else if (mode == 1) {
                if (e->sub == 1) return e->value;
            } else {
                return e->value;
            }
        }
    }
    return 0;
}
